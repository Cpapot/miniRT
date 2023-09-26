/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:41:35 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 20:28:15 by cpapot           ###   ########.fr       */
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
void	print_loading(int cam);
bool	parsing(t_data *data_pt, char *file_name);
t_data	create_struct(void);
void	change_cylinder_coord(t_data *data_pt);
bool	add_disk(t_data *data_pt);

void	render(t_data *data, t_mlx_info *win, int x, int y)
{
	t_ray	camray;

	if (data->option.anti_aliasing == false)
	{
		camray = find_camray(data->camera[data->option.tmp], x, y);
		my_mlx_pixel_put(win, x, y, mod_gamma(check_ray(camray, *data, 0)));
	}
	else
		my_mlx_pixel_put(win, x, y, mod_gamma(anti_aliasing(data, x, y, \
			data->camera[data->option.tmp])));
	print_loading(data->option.tmp + 1);
}

void	render_image(t_mlx_info *win, t_data *data, int cam)
{
	int		x;
	int		y;

	win->img = mlx_new_image(win->mlx_ptr, win->xwinsize, win->ywinsize);
	win->img_addrs = mlx_get_data_addr(win->img, &win->bit_per_p,
			&win->line_len, &win->endian);
	data->option.tmp = cam;
	x = 0;
	set_data(data, &data->camera[data->option.tmp]);
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
}

t_img_info	*render_all_img(t_mlx_info *win, t_data *data)
{
	int		cam_index;
	t_img_info	*img_array;

	cam_index = 0;
	img_array = malloc(sizeof(t_img_info) * (int)data->ca_nb);
	while (cam_index != (int)data->ca_nb)
	{
		render_image(win, data, cam_index);
		img_array[cam_index].img = win->img;
		img_array[cam_index].img_addrs = win->img_addrs;
		cam_index++;
	}
	return (img_array);
}

void	screen_loop(t_mlx_info *win, t_data *data)
{
	print_info(data);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_arr[data->option.cam_id].img, 0, 0);
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
	change_cylinder_coord(&data);
	if (!add_disk(&data))
		return (1);
	ft_create_win(&win);
	win.img_arr = render_all_img(&win, &data);
	screen_loop(&win, &data);
	info.data = &data;
	info.win = &win;
	mlx_hook(win.win_ptr, 17, 0, close_window, "close");
	mlx_hook(win.win_ptr, 2, 1L << 0, deal_key, &info);
	mlx_loop(win.mlx_ptr);
}
