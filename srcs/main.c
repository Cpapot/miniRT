/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:41:35 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/13 13:13:02 by cpapot           ###   ########.fr       */
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

	cam.origin.x = 4;
	cam.origin.y = 0;
	cam.origin.z = 0;
	cam.vector = set_vec(-1, 0, 0);
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

void	screen_loop(t_mlx_info *win/*, t_light light*/)
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
			if(sphere_hited(camray, init_sphere()) != -1)
				my_mlx_pixel_put(win, x, y, test_color(find_sphere_hit_coord(sphere_hited(camray, init_sphere()), camray)));
			else
				my_mlx_pixel_put(win, x, y, ft_color(0, 0, 0, 0));
			y++;
		}
		x++;
	}
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
	(void)ac;
	t_mlx_info	win;
	t_minirt_data	data;

	init_minirt_data(&data);
	if (parsing(&data, av[1]) == false)
		return (1);
	print_data("main", &data);
	return (0);
	ft_create_win(&win);
	screen_loop(&win/*, init_light()*/);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img, 0, 0);
	mlx_loop(win.mlx_ptr);
}
