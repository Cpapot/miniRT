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

int32_t	test_color(t_point hitpoint)
{
	return (ft_color(100 * (hitpoint.x + 1), 100 * (hitpoint.y + 1), 100 * (hitpoint.z + 1), 10));
}


t_light		init_light()
{
	t_light	light;

	light.vector = set_vec(1, -10, 8);
	calculate_norm(&light.vector);
	return (light);
}

t_sphere	init_sphere()
{
	t_sphere	sphere;

	sphere.diameter = 2;
	sphere.origin.x = 0;
	sphere.origin.y = 0;
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
			my_mlx_pixel_put(win, x, y, check_ray(camray, create_struct()));
			y++;
		}
		x++;
	}
	ft_printf(GREEN"RENDER COMPLETE\n"WHITE);
}

bool	parsing(t_minirt_data *data_pt, char *file_name);

void	print_data(char *msg, t_minirt_data *data);

void	init_minirt_data(t_minirt_data * data)
{
	data->sp_nb = 0;
	data->pl_nb = 0;
	data->cy_nb = 0;
	data->lt_nb = 0;
	data->al_nb = 0;
	data->ca_nb = 0;
}

int main(int ac, char **av)
{
	t_mlx_info		win;
	(void)ac;
	t_minirt_data	data;

	init_minirt_data(&data);
	if (parsing(&data, av[1]) == false)
		return (1);
	print_data("main", &data);
	ft_create_win(&win);
	screen_loop(&win);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img, 0, 0);
	mlx_loop(win.mlx_ptr);
}
