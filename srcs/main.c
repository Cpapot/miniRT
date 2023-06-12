/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:41:35 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/12 18:31:32 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

/**/
#include "../inc/camera.h"

int32_t ft_color(int r, int g, int b, int T)
{
	return T << 24 | r << 16 | g << 8 | b << 0;
}

t_camera	init_test_cam(void)
{
	t_camera	cam;

	cam.origin.x = 10;
	cam.origin.y = 0;
	cam.origin.z = 0;
	cam.vector = set_vec(-1, 0, 0);
	cam.fov = 60.0;
	return (cam);
}

int32_t	test_color(double dot)
{
	dot = dot *3;
	return (ft_color(92 * dot, 38 * dot, 145 * dot, 0));
}

t_light		init_light()
{
	t_light	light;

	light.vector = set_vec(0, -10, 0);
	return (light);
}

t_sphere	init_sphere()
{
	t_sphere	sphere;

	sphere.diameter = 10;
	sphere.origin.x = 0;
	sphere.origin.y = -5;
	sphere.origin.z = 0;
	return (sphere);
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
			if(sphere_hited(camray, init_sphere()))
				my_mlx_pixel_put(win, x, y, test_color(ft_find_light(camray.direction, init_light())));
			else
				my_mlx_pixel_put(win, x, y, ft_color(0, 0, 0, 0));
			y++;
		}
		x++;
	}
}

int main()
{
	t_mlx_info	win;

	ft_create_win(&win);
	screen_loop(&win);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img, 0, 0);
	//hook
	mlx_loop(win.mlx_ptr);
}
