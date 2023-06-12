/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:41:35 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/12 17:13:39 by cpapot           ###   ########.fr       */
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

	cam.origin.x = 20;
	cam.origin.y = 0;
	cam.origin.z = 0;
	cam.vector = set_vec(-1, 0, 0);
	cam.fov = 90.0;
	return (cam);
}

int32_t	test_color(t_vec_3	vec)
{
	double	t;

	t = 0.5 * (vec.y + 1);
	return (ft_color((1.0 - t) * 1.0 + t * 0.5, (1.0 - t) * 1.0 + t * 0.7, (1.0 - t) * 1 + t * 1.0, 0));
}

t_light		init_light()
{
	t_light	light;

	light.vector = set_vec(1, 0, 0);
	return (light);
}

t_sphere	init_sphere()
{
	t_sphere	sphere;

	sphere.diameter = 10;
	sphere.origin.x = 15;
	sphere.origin.y = 5;
	sphere.origin.z = 5;
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
				my_mlx_pixel_put(win, x, y, ft_color(92, 38, 145, 0));
			else
				my_mlx_pixel_put(win, x, y, test_color(camray.direction));
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
