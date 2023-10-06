/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:40:45 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/26 16:10:40 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"
#include "reflection.h"
#include "light.h"

double	quadratic_equation(double a, double b, double c);
int		cut_infinite_object(t_point p, t_point coord, t_vec_3 norm, double h);
t_hit	quadratic_equation_inside(double a, double b, double c);
t_hit	set_hit(bool inside, double t);

t_vec_3	cone_normal(t_ray camray, double t, t_cone cone)
{
	double	k;
	double	scalar;
	t_vec_3	result;
	t_vec_3	tmp;
	t_point	hitpoint;

	hitpoint = hit_coord(t, camray);
	k = tan((cone.diameter / 2) * M_PI / 180.0);
	tmp = set_vec(camray.origin.x - cone.coordinate.x, camray.origin.y - \
		cone.coordinate.y, camray.origin.z - cone.coordinate.z);
	scalar = scalar_product(camray.direction, set_vec(hitpoint.x, hitpoint.y, \
		hitpoint.z)) + scalar_product(tmp, cone.vector);
	tmp = set_vec(hitpoint.x + camray.origin.x, hitpoint.y + camray.origin.y, \
		hitpoint.z + camray.origin.z);
	result = minus_vec(minus_vec(tmp, set_vec(cone.coordinate.x, \
		cone.coordinate.y, cone.coordinate.z)), multip_vec(cone.vector, \
		((1 + pow(k, 2.0))) * scalar));
	normalize_vec(&result);
	return (result);
}

bool	is_inside_cone(t_cone cone, t_point hitpoint)
{
	t_vec_3	tmp;
	double	dist;
	double	rad;
	double	orth;

	tmp = set_vec(hitpoint.x - cone.coordinate.x, hitpoint.y - \
		cone.coordinate.y, hitpoint.z - cone.coordinate.z);
	dist = scalar_product(tmp, cone.vector);
	rad = (dist / cone.height) * (cone.diameter / 2);
	tmp = minus_vec(tmp, multip_vec(cone.vector, dist));
	orth = calculate_norm(&tmp);
	if (orth < rad)
		return (true);
	return (false);
}

t_hit	cone_hitted(t_ray camray, t_cone cone)
{
	double	quad[3];
	double	tmp[3];
	t_hit	t;
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
	t = quadratic_equation_inside(quad[0], quad[1], quad[2]);
	tmp[0] = camray.origin.y + t.t * camray.direction.y;
	hitpoint = hit_coord(t.t, camray);
	if (cut_infinite_object(hitpoint, cone.coordinate, cone.vector, \
		cone.height))
		return (set_hit(0, -1));
	return (set_hit(is_inside_cone(cone, hitpoint), t.t));
}

t_hit	find_near_cone(t_ray camray, size_t count, t_cone *cone_arr)
{
	size_t	index;
	double	tmp;
	t_hit	t;
	t_hit	info;

	info.id = -1;
	index = 0;
	tmp = INT_MAX;
	while (index != count)
	{
		t = cone_hitted(camray, cone_arr[index]);
		if (tmp > t.t && (t.t != -1 || t.t == -2))
		{
			tmp = t.t;
			info.id = index;
			info.inside = t.inside;
		}
		index++;
	}
	info.t = tmp;
	return (info);
}

int32_t	render_cone(t_hitinfo info, t_ray camray, t_data data, int level)
{
	t_cone		*co;
	t_color		ratio;
	t_point		hit;
	t_ray		reflect_ray;

	co = (t_cone *)info.struct_info;
	if (info.inside)
		info.normal = multip_vec(cone_normal(camray, info.t, *co), -1);
	else
		info.normal = cone_normal(camray, info.t, *co);
	hit = adjust_hitpoint(hit_coord(info.t, camray), \
		info.normal);
	ratio = light_ratio(hit_coord(info.t, camray), data, \
info.normal, &co->material);
	ambient_lightning(&ratio, &data);
	reflect_ray.direction = reflect_vec(info.normal, \
		camray.direction);
	reflect_ray.origin = hit;
	data.level = level;
	return (reflection(ft_color(co->color.r * ratio.r, co->color.g * \
	ratio.g, co->color.b * ratio.b, 0), data, reflect_ray, \
		&co->material));
}
