/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:41:35 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 17:12:27 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

/**/
#include "../inc/camera.h"
#include "../inc/color.h"
#include "../inc/key.h"
#include "../inc/light.h"
/**/

void	set_data(t_data *data, t_camera *cam);
int32_t	mod_gamma(int32_t object_color);
void	print_loading(void);
bool	parsing(t_data *data_pt, char *file_name);
t_data	create_struct(void);
void	change_cylinder_coord(t_data *data_pt);
bool	add_disk(t_data *data_pt);

void	render(t_data *data, t_mlx_info *win, int x, int y)
{
	t_ray	camray;

	if (data->option.anti_aliasing == false)
	{
		camray = find_camray(data->camera[data->option.cam_id], x, y);
		my_mlx_pixel_put(win, x, y, mod_gamma(check_ray(camray, *data, 0)));
	}
	else
		my_mlx_pixel_put(win, x, y, mod_gamma(anti_aliasing(data, x, y, \
			data->camera[data->option.cam_id])));
	print_loading();
}

void	screen_loop(t_mlx_info *win, t_data *data)
{
	int		x;
	int		y;

	x = 0;
	set_data(data, &data->camera[data->option.cam_id]);
	while (x != win->xwinsize)
	{
		y = 0;
		while (y != win->ywinsize)
		{
			render(data, win, x, y);
			y++;
		}
		x++;
	}
	print_info(data);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img, 0, 0);
}

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->option.cam_id = 0;
	data->option.shadow = true;
	data->option.anti_aliasing = false;
}

int	clean_minirt_data(t_data *data_pt)
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

int	main(int ac, char **av)
{
	t_general		info;
	t_mlx_info		win;
	t_data			data;

	init_data(&data);
	if (ac == 1 || parsing(&data, av[1]) == false)
		return (clean_minirt_data(&data));
	ft_printf("\e[2J\e[H");
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
