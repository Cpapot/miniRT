/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:41:35 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/14 17:56:54 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

/**/
#include "../inc/camera.h"
#include "../inc/colors.h"

t_camera	init_test_cam(void)
{
	t_camera	cam;

	cam.origin.x = -5;
	cam.origin.y = 0;
	cam.origin.z = 0;
	cam.vector = set_vec(1, 0, 0);
	normalize_vec(&cam.vector);
	cam.fov = 90.0;
	return (cam);
}

/**/

void	screen_loop(t_mlx_info *win)
{
	t_ray	camray;
	int		x;
	int		y;

	x = 0;
	while (x != win->xwinsize)
	{
		y = 0;
		while (y != win->ywinsize)
		{
			camray = find_camray(init_test_cam(), x, y);
			my_mlx_pixel_put(win, x, y, check_ray(camray, create_struct()));
			y++;
		}
		x++;
	}
	ft_printf(GREEN"RENDER COMPLETE\n"WHITE);
}

int main()
{
	t_mlx_info		win;

	ft_create_win(&win);
	screen_loop(&win);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img, 0, 0);
	//hook
	mlx_loop(win.mlx_ptr);
}
