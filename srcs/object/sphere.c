/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:49:10 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:45:22 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "reflection.h"
#include "material.h"
#include "light.h"

t_hit	quadratic_equation_inside(double a, double b, double c);
t_point	sphere_mapping(t_point point, double radius);
t_hit	set_hit(bool inside, double t);

t_vec_3	sphere_normal(t_ray camray, double t, t_point center)
{
	t_point	hitpoint;
	t_vec_3	result;

	hitpoint = hit_coord(t, camray);
	result.x = hitpoint.x - center.x;
	result.y = hitpoint.y - center.y;
	result.z = hitpoint.z - center.z;
	normalize_vec(&result);
	return (result);
}

t_hit	sphere_hited(t_ray ray, t_sphere sphere)
{
	double	a;
	double	b;
	double	c;
	t_vec_3	sphere_vect;

	sphere_vect.x = ray.origin.x - sphere.origin.x;
	sphere_vect.y = ray.origin.y - sphere.origin.y;
	sphere_vect.z = ray.origin.z - sphere.origin.z;
	a = scalar_product(ray.direction, ray.direction);
	b = 2 * scalar_product(ray.direction, sphere_vect);
	c = scalar_product(sphere_vect, sphere_vect) - pow((sphere.diameter) \
		/ 2.0, 2);
	return (quadratic_equation_inside(a, b, c));
}

t_hit	find_near_sphere(t_ray camray, size_t count, t_sphere *sphere_arr)
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
		t = sphere_hited(camray, sphere_arr[index]);
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

int32_t	render_sphere(t_hitinfo info, t_ray camray, t_data data, int level)
{
	t_sphere	*sp;
	t_color		ratio;
	t_point		hit;
	t_ray		reflect_ray;

	sp = (t_sphere *)info.struct_info;
	if (info.inside)
		info.normal = multip_vec(sphere_normal(camray, info.t, sp->origin), -1);
	else
		info.normal = sphere_normal(camray, info.t, sp->origin);
	hit = adjust_hitpoint(hit_coord(info.t, camray), \
		info.normal);
	ratio = light_ratio(hit, data, info.normal, &sp->material);
	ambient_lightning(&ratio, &data);
	reflect_ray.direction = reflect_vec(info.normal, camray.direction);
	reflect_ray.origin = hit;
	data.level = level;
	return (reflection(ft_color(sp->color.r * ratio.r, sp->color.g * \
		ratio.g, sp->color.b * ratio.b, 0), data, reflect_ray, \
		&sp->material));
}
