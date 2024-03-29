/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:54:31 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/26 20:28:01 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"
#include "reflection.h"
#include "light.h"

t_hit	quadratic_equation_inside(double a, double b, double c);
int		cut_infinite_object(t_point p, t_point coord, t_vec_3 norm, double h);
t_hit	set_hit(bool inside, double t);

t_vec_3	cylinder_normal(t_ray camray, double t, t_cylinder cyl)
{
	t_vec_3	result;
	t_point	hit;
	t_vec_3	dot;

	hit = hit_coord(t, camray);
	dot = set_vec(hit.x, hit.y, hit.z);
	result = minus_vec(adding_vec(set_vec(cyl.coord.x, cyl.coord.y, \
		cyl.coord.z), multip_vec(cyl.normal, scalar_product(\
		minus_vec(dot, set_vec(cyl.coord.x, cyl.coord.y, \
		cyl.coord.z)), cyl.normal))), dot);
	multiplying_vec(&result, -1);
	normalize_vec(&result);
	return (result);
}

t_hit	cylinder_hitted(t_ray camray, t_cylinder cyl)
{
	double	quad[3];
	t_hit	t;
	t_point	p;
	t_vec_3	vec[3];
	t_vec_3	tmp;

	vec[0] = set_vec(camray.origin.x - cyl.coord.x, camray.origin.y - \
		cyl.coord.y, camray.origin.z - cyl.coord.z);
	tmp = cyl.normal;
	multiplying_vec(&tmp, scalar_product(camray.direction, cyl.normal));
	vec[1] = set_vec(camray.direction.x - tmp.x, camray.direction.y - tmp.y, \
		camray.direction.z - tmp.z);
	tmp = cyl.normal;
	multiplying_vec(&tmp, scalar_product(vec[0], cyl.normal));
	vec[2] = set_vec(vec[0].x - tmp.x, vec[0].y - tmp.y, vec[0].z - tmp.z);
	quad[0] = scalar_product(vec[1], vec[1]);
	if (quad[0] <= 0)
		return (set_hit(0, -1));
	quad[1] = 2 * scalar_product(vec[1], vec[2]);
	quad[2] = scalar_product(vec[2], vec[2]) - pow(cyl.diameter / 2, 2);
	t = quadratic_equation_inside(quad[0], quad[1], quad[2]);
	p = hit_coord(t.t, camray);
	if (cut_infinite_object(p, cyl.coord, cyl.normal, cyl.height))
		return (set_hit(0, -1));
	return (t);
}

t_hit	find_near_cylinder(t_ray camray, size_t count, t_cylinder *cyl_arr)
{
	size_t		index;
	double		tmp;
	t_hit		t;
	t_hit		info;

	info.id = -1;
	index = 0;
	tmp = INT_MAX;
	while (index != count)
	{
		t = cylinder_hitted(camray, cyl_arr[index]);
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

int32_t	render_cylinder(t_hitinfo info, t_ray camray, t_data data, int level)
{
	t_cylinder	*cy;
	t_color		ratio;
	t_point		hit;
	t_ray		reflect_ray;

	cy = (t_cylinder *)info.struct_info;
	if (info.inside)
		info.normal = multip_vec(cylinder_normal(camray, info.t, *cy), -1);
	else
		info.normal = cylinder_normal(camray, info.t, *cy);
	hit = adjust_hitpoint(hit_coord(info.t, camray), \
		info.normal);
	ratio = light_ratio(hit, data, info.normal, &cy->material);
	ambient_lightning(&ratio, &data);
	reflect_ray.direction = reflect_vec(info.normal, camray.direction);
	reflect_ray.origin = hit;
	data.level = level;
	return (reflection(ft_color(cy->color.r * ratio.r, cy->color.g * \
		ratio.g, cy->color.b * ratio.b, 0), data, reflect_ray, \
		&cy->material));
}
