/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:11:11 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/27 13:29:56 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "camera.h"
#include "close.h"

void	set_data(t_data *data, t_camera *cam);
int32_t	mod_gamma(int32_t object_color);
void	print_loading(int cam);

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
	int			cam_index;
	t_img_info	*img_array;

	cam_index = 0;
	img_array = malloc(sizeof(t_img_info) * (int)data->ca_nb);
	if (img_array == NULL)
		close_minirt(win, data, 1);
	while (cam_index != (int)data->ca_nb)
	{
		render_image(win, data, cam_index);
		img_array[cam_index].img = win->img;
		img_array[cam_index].img_addrs = win->img_addrs;
		cam_index++;
	}
	return (img_array);
}
