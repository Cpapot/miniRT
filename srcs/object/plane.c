/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:01:59 by cpapot            #+#    #+#             */
/*   Updated: 2023/08/01 22:05:28 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "checkerboard.h"
#include "reflection.h"

t_vec_3	plane_normal(t_vec_3 camdir, t_plane plane)
{
	double	scalar;
	t_vec_3	tmp;

	tmp.x = camdir.x - plane.normal_vector.x;
	tmp.y = camdir.y - plane.normal_vector.y;
	tmp.z = camdir.z - plane.normal_vector.z;
	normalize_vec(&tmp);
	normalize_vec(&camdir);
	scalar = scalar_product(tmp, camdir);
	if (scalar < 0)
		multiplying_vec(&plane.normal_vector, -1);
	return (plane.normal_vector);
}

double	plane_hited(t_ray ray, t_plane plane)
{
	double	d;
	double	t;
	t_vec_3	origin;

	if (scalar_product(plane.normal_vector, ray.direction) == 0)
		return (-1);
	d = -(plane.normal_vector.x * plane.coordinate.x + plane.normal_vector.y \
	* plane.coordinate.y + plane.normal_vector.z * plane.coordinate.z);
	origin.x = ray.origin.x;
	origin.y = ray.origin.y;
	origin.z = ray.origin.z;
	t = -(scalar_product(plane.normal_vector, origin) + d) \
		/ scalar_product(plane.normal_vector, ray.direction);
	if (t > 0)
		return (t);
	else
		return (-1);
}

t_hit	find_near_plane(t_ray camray, size_t count, t_plane *plane_arr)
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
		t = plane_hited(camray, plane_arr[index]);
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

int32_t	render_plane(t_hitinfo info, t_ray camray, t_minirt_data data, int level)
{
	t_plane		*pl;
	t_color		ratio;
	t_point	hit;
	double		material[3];
	t_ray		reflect_ray;

	material[0] = 0.4;
	material[1] = 10;
	material[2] = PLANE;
	pl = (t_plane *)info.struct_info;
	hit = adjust_hitpoint(hit_coord(info.t, camray), pl->normal_vector);
	if (is_black_case(hit))
		return (ft_color(0, 0, 0, 0));
	ratio = ft_find_light_ratio(hit, data, \
	pl->normal_vector, material);
	ambient_lightning(&ratio, &data);
	reflect_ray.direction = reflect_vec(pl->normal_vector, camray.direction);
	reflect_ray.origin = hit;
	return (reflection(ft_color(pl->color.r * ratio.r, pl->color.g * \
		ratio.g, pl->color.b * ratio.b, 0), data, reflect_ray, level, NULL));
}
