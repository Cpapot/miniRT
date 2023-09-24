/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:28:39 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/24 16:41:13 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "miniRT.h"
#include "checkerboard.h"
#include "reflection.h"

t_plane	disk_to_plane(t_disk disk)
{
	t_plane	result;

	result.color = disk.color;
	result.coordinate = disk.coordinate;
	result.normal_vector = disk.normal_vector;
	return (result);
}

double	disk_hited(t_ray ray, t_disk disk)
{
	double	t;
	t_vec_3	disk_vec;
	t_point	hitpoint;

	t = plane_hited(ray, disk_to_plane(disk));
	if (t < 0)
		return (t);
	hitpoint = hit_coord(t, ray);
	disk_vec = set_vec(hitpoint.x - disk.coordinate.x, hitpoint.y - \
	disk.coordinate.y, hitpoint.z - disk.coordinate.z);
	if (sqrtf(scalar_product(disk_vec, disk_vec)) <= disk.diameter / 2)
		return (t);
	else
		return (-1);
}

t_hit	find_near_disk(t_ray camray, size_t count, t_disk *disk_arr)
{
	size_t	index;
	double	tmp;
	double	t;
	t_hit	info;

	info.id = -1;
	index = 0;
	tmp = INT_MAX;
	while (index != count)
	{
		t = disk_hited(camray, disk_arr[index]);
		if (tmp > t && t != -1)
		{
			tmp = t;
			info.id = index;
		}
		index++;
	}
	info.t = tmp;
	return (info);
}

int32_t	render_disk(t_hitinfo info, t_ray camray, t_data data, int level)
{
	t_disk		*disk;
	t_color		ratio;
	t_point		hitpoint;
	t_ray		reflect_ray;

	disk = (t_disk *)info.struct_info;
	hitpoint = adjust_hitpoint(hit_coord(info.t, camray), disk->normal_vector);
	if (disk->material.is_board && is_black_case(hitpoint))
		return (ft_color(0, 0, 0, 0));
	ratio = ft_find_light_ratio(hitpoint, data, \
	disk->normal_vector, &disk->material);
	ambient_lightning(&ratio, &data);
	reflect_ray.direction = reflect_vec(disk->normal_vector, camray.direction);
	reflect_ray.origin = hitpoint;
	data.level = level;
	return (reflection(ft_color(disk->color.r * ratio.r, disk->color.g * \
		ratio.g, disk->color.b * ratio.b, 0), data, reflect_ray, \
		&disk->material));
}
