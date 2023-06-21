/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:41:35 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/21 17:20:26 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

/**/
#include "../inc/camera.h"
#include "../inc/color.h"
#include "../inc/key.h"
#include "light.h"
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

void	set_minirt_data(t_minirt_data *data, t_camera *cam)
{
	int						index;
	t_plane					plane;

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
	reset_light(data);
	delete_hidden_light(data, cam->origin);
}

void	screen_loop(t_mlx_info *win, t_minirt_data *data)
{
	t_ray	camray;
	int		x;
	int		y;

	x = 0;
	set_minirt_data(data, &data->camera[0]);
	ft_printf(GREEN"Loading scenes ["YELLOW);
	while (x != win->xwinsize)
	{
		y = 0;
		while (y != win->ywinsize)
		{
			camray = find_camray(data->camera[0], x, y);
			my_mlx_pixel_put(win, x, y, check_ray(camray, *data));
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
	t_minirt_data tmp;

	tmp = create_struct();
	data->option.shadow = false;
	data->sp_nb = 0;
	data->pl_nb = 0;
	data->cy_nb = 0;
	data->lt_nb = 0;
	data->al_nb = 0;
	data->ca_nb = 0;
	data->co_nb = tmp.co_nb;
	data->cone_arr = tmp.cone_arr;
}

void	*suppress_light(t_light light, t_minirt_data *data_pt);
void	print_data(char *msg, t_minirt_data *data);

int main(int ac, char **av)
{
	t_general		info;
	t_mlx_info		win;
	(void)ac;
	(void)av;
	t_minirt_data	data;

	init_minirt_data(&data);
	if (ac > 1)
	{
		if (parsing(&data, av[1]) == false)
			return (1);
		print_data("main", &data);
	}
	else
		return (1);
	ft_create_win(&win);
	screen_loop(&win, &data);
	info.data = data;
	info.win = win;
	mlx_hook(win.win_ptr, 17, 0, close_window, "close");
	mlx_hook(win.win_ptr, 2, 1L << 0, deal_key, &info);
	mlx_loop(win.mlx_ptr);
}
