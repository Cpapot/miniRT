/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:41:35 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/27 02:29:23 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "camera.h"
#include "color.h"
#include "key.h"
#include "light.h"
#include "close.h"

bool		parsing(t_data *data_pt, char *file_name);
t_data		create_struct(void);
void		change_cylinder_coord(t_data *data_pt);
bool		add_disk(t_data *data_pt);
t_img_info	*render_all_img(t_mlx_info *win, t_data *data);

void	screen_loop(t_mlx_info *win, t_data *data)
{
	print_info(data);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->img_arr[data->option.cam_id].img, 0, 0);
}

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->option.cam_id = 0;
	data->option.shadow = true;
	data->option.anti_aliasing = false;
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
