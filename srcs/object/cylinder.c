/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:54:31 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/20 16:12:12 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"
#include "checkerboard.h"
#include "reflection.h"

double	quadratic_equation(double a, double b, double c);
int		cut_infinite_object(t_point p, t_point coord, t_vec_3 norm, double h);

t_vec_3	cylinder_normal(t_ray camray, double t, t_cylinder cyl)
{
	t_vec_3	result;
	t_point	hit;
	t_vec_3	dot;

	hit = hit_coord(t, camray);
	dot = set_vec(hit.x, hit.y, hit.z);
	result = minus_vec(adding_vec(set_vec(cyl.coordinate.x, cyl.coordinate.y, \
		cyl.coordinate.z), multip_vec(cyl.normal_vector, scalar_product(\
		minus_vec(dot, set_vec(cyl.coordinate.x, cyl.coordinate.y, \
		cyl.coordinate.z)), cyl.normal_vector))), dot);
	multiplying_vec(&result, -1);
	normalize_vec(&result);
	return (result);
}

double	cylinder_hitted(t_ray camray, t_cylinder cyl)
{
	double	quad[3];
	double	t;
	t_point	p;
	t_vec_3	vec[3];
	t_vec_3	tmp;

	vec[0] = set_vec(camray.origin.x - cyl.coordinate.x, camray.origin.y - \
		cyl.coordinate.y, camray.origin.z - cyl.coordinate.z);
	tmp = cyl.normal_vector;
	multiplying_vec(&tmp, scalar_product(camray.direction, cyl.normal_vector));
	vec[1] = set_vec(camray.direction.x - tmp.x, camray.direction.y - tmp.y, \
		camray.direction.z - tmp.z);
	tmp = cyl.normal_vector;
	multiplying_vec(&tmp, scalar_product(vec[0], cyl.normal_vector));
	vec[2] = set_vec(vec[0].x - tmp.x, vec[0].y - tmp.y, vec[0].z - tmp.z);
	quad[0] = scalar_product(vec[1], vec[1]);
	if (quad[0] <= 0)
		return (-1);
	quad[1] = 2 * scalar_product(vec[1], vec[2]);
	quad[2] = scalar_product(vec[2], vec[2]) - pow(cyl.diameter / 2, 2);
	t = quadratic_equation(quad[0], quad[1], quad[2]);
	p = hit_coord(t, camray);
	if (cut_infinite_object(p, cyl.coordinate, cyl.normal_vector, cyl.height))
		return (-1);
	return (t);
}

t_hit	find_near_cylinder(t_ray camray, size_t count, t_cylinder *cyl_arr)
{
	size_t		index;
	double		tmp;
	double		t;
	t_hit		info;

	info.id = -1;
	index = 0;
	tmp = INT_MAX;
	while (index != count)
	{
		t = cylinder_hitted(camray, cyl_arr[index]);
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

int32_t	render_cylinder(t_hitinfo info, t_ray camray, t_minirt_data data, int level)
{
	t_cylinder	*cy;
	t_color		ratio;
	t_point		hit;
	t_ray		reflect_ray;

	cy = (t_cylinder *)info.struct_info;
	hit = adjust_hitpoint(hit_coord(info.t, camray), \
		cylinder_normal(camray, info.t, *cy));
	if (cy->material.is_board && is_black_case(hit))
		return (ft_color(0, 0, 0, 0));
	ratio = ft_find_light_ratio(hit, data, \
	cylinder_normal(camray, info.t, *cy), &cy->material);
	ambient_lightning(&ratio, &data);
	reflect_ray.direction = reflect_vec(cylinder_normal(camray, info.t, \
		*cy), camray.direction);
	reflect_ray.origin = hit;
	return (reflection(ft_color(cy->color.r * ratio.r, cy->color.g * \
		ratio.g, cy->color.b * ratio.b, 0), data, reflect_ray, level, \
		&cy->material));
}
