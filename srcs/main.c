/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:41:35 by cpapot            #+#    #+#             */
/*   Updated: 2023/08/01 22:34:07 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

/**/
#include "../inc/camera.h"
#include "../inc/color.h"
#include "../inc/key.h"
#include "../inc/light.h"
/**/

//on dois la set pour chaque camera

void	reset_light(t_minirt_data *data)
{
	static t_light			first_data[LIGHT_BUFF];
	int						i;
	static int				index = 0;
	static int				lt_nb;

	i = 0;
	if (index == 0)
	{
		lt_nb = data->lt_nb;
		while (i != lt_nb && i != LIGHT_BUFF)
		{
			first_data[i] = data->lights_arr[i];
			i++;
		}
	}
	else
	{
		data->lt_nb = lt_nb;
		while (i != lt_nb && i != LIGHT_BUFF)
		{
			data->lights_arr[i] = first_data[i];
			i++;
		}
	}
	index++;
}

t_plane	disk_to_plane(t_disk disk);

void	set_minirt_data(t_minirt_data *data, t_camera *cam)
{
	int						index;
	t_plane					plane;
	t_disk					disk;

	index = 0;
	normalize_vec(&cam->vector);
	if (cam->vector.y == 0)
		cam->vector.y = 0.0000001;
	while (data->pl_nb != (size_t)index)
	{
		plane = data->plane_arr[index];
		data->plane_arr[index].normal_vector = plane_normal(cam->vector, plane);
		index++;
	}
	index = 0;
	while (data->di_nb != (size_t)index)
	{
		disk = data->disk_arr[index];
		data->disk_arr[index].normal_vector = plane_normal(cam->vector, disk_to_plane(disk));
		index++;
	}
	reset_light(data);
	delete_hidden_light(data, cam->origin);
}

int32_t	mod_gamma(int32_t object_color);

void	screen_loop(t_mlx_info *win, t_minirt_data *data)
{
	t_ray	camray;
	int		x;
	int		y;

	x = 0;
	set_minirt_data(data, &data->camera[data->option.cam_id]);
	ft_printf(GREEN"Loading scenes ["YELLOW);
	while (x != win->xwinsize)
	{
		y = 0;
		while (y != win->ywinsize)
		{
			if (data->option.anti_aliasing == false)
			{
				camray = find_camray(data->camera[data->option.cam_id], x, y);
				my_mlx_pixel_put(win, x, y, mod_gamma(check_ray(camray, *data, 0)));
			}
			else
				my_mlx_pixel_put(win, x, y, mod_gamma(anti_aliasing(data, x, y, data->camera[data->option.cam_id])));
			y++;
		}
		x++;
		if (x % 25 == 0)
			ft_printf("■");
	}
	ft_printf(GREEN" ]\n"WHITE);
	print_info(data);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img, 0, 0);
}

bool	parsing(t_minirt_data *data_pt, char *file_name);
t_minirt_data	create_struct();

void	init_minirt_data(t_minirt_data * data)
{
    ft_bzero(data, sizeof(t_minirt_data));
	data->option.cam_id = 0;
	data->option.shadow = true;
	data->option.anti_aliasing = false;
}

void	*suppress_light(t_light light, t_minirt_data *data_pt);
void	print_data(char *msg, t_minirt_data *data);
void	change_cylinder_coord(t_minirt_data *data_pt);
bool	add_disk(t_minirt_data *data_pt);

int    clean_minirt_data(t_minirt_data *data_pt)
{
    if (data_pt->ambient_light != NULL)
        free(data_pt->ambient_light);
    if (data_pt->camera != NULL)
        free(data_pt->camera);
    if (data_pt->lights_arr != NULL)
        free(data_pt->lights_arr);
    if (data_pt->sphere_arr != NULL)
        free(data_pt->sphere_arr);
    if (data_pt->plane_arr != NULL)
        free(data_pt->plane_arr);
    if (data_pt->cylinder_arr != NULL)
        free(data_pt->cylinder_arr);
    if (data_pt->cone_arr != NULL)
        free(data_pt->cone_arr);
    if (data_pt->disk_arr != NULL)
        free(data_pt->disk_arr);
  return (1);  
}
#include <stdio.h>

void    usage_display(void)
{
    dprintf(2, "Usage is : ./MiniRT [ARGUMENTS]\n%s",
        "ARGUMENTS must be a .rt file with at least one camera\n");
}

int main(int ac, char **av)
{
	t_general		info;
	t_mlx_info		win;
	(void)ac;
	(void)av;
	t_minirt_data	data;

	init_minirt_data(&data);
	if (ac == 1  || parsing(&data, av[1]) == false)
        return (usage_display(), clean_minirt_data(&data));
    print_data("main", &data);
	change_cylinder_coord(&data);
	if (!add_disk(&data))
		return (1);
	ft_create_win(&win);
	screen_loop(&win, &data);
	info.data = data;
	info.win = win;
	mlx_hook(win.win_ptr, 17, 0, close_window, "close");
	mlx_hook(win.win_ptr, 2, 1L << 0, deal_key, &info);
	mlx_loop(win.mlx_ptr);
}
