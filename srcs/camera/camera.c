/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:56:27 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/24 17:50:51 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

static double	mapping_xcoord(int pixel_pos, double fov, int index)
{
	double	result;
	double	ratio;
	double	scale;

	scale = tan(fov / 2.0 * M_PI / 180);
	ratio = (double)XSIZE / (double)YSIZE;
	if (index <= 1)
		result = ((double)pixel_pos + 0.25) / ((double)XSIZE);
	else
		result = ((double)pixel_pos + 0.75) / ((double)XSIZE);
	result = (2 * result - 1) * ratio * scale;
	return (result);
}

static double	mapping_ycoord(int pixel_pos, double fov, int index)
{
	double	result;
	double	scale;

	scale = tan(fov / 2.0 * M_PI / 180);
	if (index == 1 || index == 3)
		result = ((double)pixel_pos + 0.25) / ((double)YSIZE);
	else
		result = ((double)pixel_pos + 0.75) / ((double)YSIZE);
	result = (2 * result - 1) * scale;
	result *= -1;
	return (result);
}

static t_vec_3	compute_direction(t_vec_3 cam_vector, t_vec_3 ray_dir)
{
	t_vec_3	result;
	t_vec_3	x;
	t_vec_3	y;

	if (cam_vector.y == 1 || cam_vector.y == -1)
		x = set_vec(cam_vector.y, 0, 0);
	else
		x = vect_product(set_vec(0, 1, 0), cam_vector);
	y = vect_product(cam_vector, x);
	result.x = ray_dir.x * x.x + ray_dir.y * y.x + ray_dir.z * cam_vector.x;
	result.y = ray_dir.x * x.y + ray_dir.y * y.y + ray_dir.z * cam_vector.y;
	result.z = ray_dir.x * x.z + ray_dir.y * y.z + ray_dir.z * cam_vector.z;
	return (result);
}

t_ray	find_camray(t_camera cam_info, int x, int y)
{
	t_vec_3	ray_dir;
	t_ray	cam_ray;

	cam_ray.origin = cam_info.origin;
	ray_dir.x = mapping_xcoord(x, cam_info.fov, 0);
	ray_dir.y = mapping_ycoord(y, cam_info.fov, 0);
	ray_dir.z = 1;
	normalize_vec(&ray_dir);
	cam_ray.direction = compute_direction(cam_info.vector, ray_dir);
	calculate_norm(&cam_ray.direction);
	return (cam_ray);
}

t_ray	find_aliasing_ray(t_camera cam_info, int x, int y, int index)
{
	t_vec_3	ray_dir;
	t_ray	cam_ray;

	cam_ray.origin = cam_info.origin;
	ray_dir.x = mapping_xcoord(x, cam_info.fov, index);
	ray_dir.y = mapping_ycoord(y, cam_info.fov, index);
	ray_dir.z = 1;
	normalize_vec(&ray_dir);
	cam_ray.direction = compute_direction(cam_info.vector, ray_dir);
	calculate_norm(&cam_ray.direction);
	return (cam_ray);
}
