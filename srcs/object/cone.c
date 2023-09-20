/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:40:45 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/20 15:55:38 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"
#include "reflection.h"

double	quadratic_equation(double a, double b, double c);
int		cut_infinite_object(t_point p, t_point coord, t_vec_3 norm, double h);

t_vec_3	cone_normal(t_ray camray, double t, t_cone cone)
{
	t_point	hitpoint;
	t_vec_3	projected_vec;
	t_vec_3	result;

	hitpoint = hit_coord(t, camray);
	projected_vec.x = hitpoint.x;
	projected_vec.y = hitpoint.y;
	projected_vec.z = hitpoint.z;
	result.x = (hitpoint.x * scalar_product(projected_vec, cone.vector)) / \
		scalar_product(projected_vec, projected_vec) - cone.vector.x;
	result.y = (hitpoint.y * scalar_product(projected_vec, cone.vector)) / \
		scalar_product(projected_vec, projected_vec) - cone.vector.y;
	result.z = (hitpoint.z * scalar_product(projected_vec, cone.vector)) / \
		scalar_product(projected_vec, projected_vec) - cone.vector.z;
	normalize_vec(&result);
	return (result);
}

double	cone_hitted(t_ray camray, t_cone cone)
{
	double	quad[3];
	double	tmp[3];
	double	t;
	t_point	hitpoint;
	t_vec_3	vec;

	normalize_vec(&cone.vector);
	tmp[2] = pow(cone.diameter / 2, 2) / pow(cone.height, 2);
	vec = set_vec(camray.origin.x - cone.coordinate.x, camray.origin.y - \
		cone.coordinate.y, camray.origin.z - cone.coordinate.z);
	tmp[0] = scalar_product(camray.direction, cone.vector);
	tmp[1] = scalar_product(vec, cone.vector);
	quad[0] = scalar_product(camray.direction, camray.direction) - tmp[2] \
		* pow(tmp[0], 2) - pow(tmp[0], 2);
	quad[1] = 2 * (scalar_product(camray.direction, vec) - tmp[2] * tmp[0] \
		* tmp[1] - tmp[0] * tmp[1]);
	quad[2] = scalar_product(vec, vec) - tmp[2] * pow(tmp[1], 2) - \
		pow(tmp[1], 2);
	t = quadratic_equation(quad[0], quad[1], quad[2]);
	tmp[0] = camray.origin.y + t * camray.direction.y;
	hitpoint = hit_coord(t, camray);
	if (cut_infinite_object(hitpoint, cone.coordinate, cone.vector, \
		cone.height))
		return (-1);
	return (t);
}

t_hit	find_near_cone(t_ray camray, size_t count, t_cone *cone_arr)
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
		t = cone_hitted(camray, cone_arr[index]);
		if (tmp > t && (t != -1 || t == -2))
		{
			tmp = t;
			info.id = index;
		}
		index++;
	}
	info.t = tmp;
	return (info);
}

int32_t	render_cone(t_hitinfo info, t_ray camray, t_minirt_data data, int level)
{
	t_cone		*co;
	t_color		ratio;
	t_point		hit;
	t_ray		reflect_ray;

	co = (t_cone *)info.struct_info;
	hit = adjust_hitpoint(hit_coord(info.t, camray), \
		cone_normal(camray, info.t, *co));
	ratio = ft_find_light_ratio(hit_coord(info.t, camray), data, \
	cone_normal(camray, info.t, *(t_cone *)info.struct_info), &co->material);
	ambient_lightning(&ratio, &data);
	reflect_ray.direction = reflect_vec(cone_normal(camray, info.t, *co), \
		camray.direction);
	reflect_ray.origin = hit;
	return (reflection(ft_color(co->color.r * ratio.r, co->color.g * \
	ratio.g, co->color.b * ratio.b, 0), data, reflect_ray, level, \
		&co->material));
}
