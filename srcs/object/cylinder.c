/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:54:31 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/27 18:26:59 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"

t_vec_3 cylinder_normal(t_ray camray, double t)
{
	t_vec_3	result;
	t_point	dot;

	dot = hit_coord(t, camray);
	result = set_vec(dot.x, 0, dot.z);
	normalize_vec(&result);
	return (result);
}

double	cylinder_hitted(t_ray camray, t_cylinder cyl)
{
	double	A;
	double	B;
	double	C;
	double	delta;
	double	t;
	t_point	hitpoint;
	t_vec_3	cyl_vect[3];
	t_vec_3	tmp;
	t_vec_3	vec;

	normalize_vec(&cyl.normal_vector);

	cyl_vect[0] = set_vec(camray.origin.x - cyl.coordinate.x, camray.origin.y - cyl.coordinate.y, camray.origin.z - cyl.coordinate.z);

	tmp = cyl.normal_vector;
	multiplying_vec(&tmp, scalar_product(camray.direction, cyl.normal_vector));
	cyl_vect[1] = set_vec(camray.direction.x - tmp.x, camray.direction.y - tmp.y, camray.direction.z - tmp.z);

	tmp = cyl.normal_vector;
	multiplying_vec(&tmp, scalar_product(cyl_vect[0], cyl.normal_vector));
	cyl_vect[2] = set_vec(cyl_vect[0].x - tmp.x, cyl_vect[0].y - tmp.y, cyl_vect[0].z - tmp.z);

	A = scalar_product(cyl_vect[1], cyl_vect[1]);
	if (A <= 0)
		return (-1);
	B = 2 * scalar_product(cyl_vect[1], cyl_vect[2]);
	C = scalar_product(cyl_vect[2], cyl_vect[2]) - pow(cyl.diameter / 2, 2);
	delta = B * B - 4 * A * C;
	if (delta < 0)
		return (-1);
	delta = sqrtf(delta);
	t = (-B - delta) / (2.0f * A);
	if (t < 0 || (((-B + delta) / (2.0f * A)) > 0 && ((-B + delta) / (2.0f * A)) < t))
		t = (-B + delta) / (2.0f * A);
	if (t < 0)
		return (-1);
	hitpoint = hit_coord(t, camray);
	vec = set_vec(hitpoint.x, hitpoint.y, hitpoint.z);
	if (scalar_product(vec, cyl.normal_vector) < 0 || scalar_product(vec, cyl.normal_vector) > cyl.height)
		return (-1);
	return (t);
}

int		find_near_cylinder(t_ray camray, size_t count, t_cylinder *cyl_arr)
{
	size_t	index;
	double	tmp;
	double	t;
	int		id;

	id = -1;
	index = 0;
	tmp = INT_MAX;
	while (index != count)
	{
		t = cylinder_hitted(camray, cyl_arr[index]);
		if (tmp > t && (t != -1 || t == -2))
		{
			tmp = t;
			id = index;
		}
		index++;
	}
	return (id);
}

int32_t	render_cylinder(t_hitinfo info, t_ray camray, t_minirt_data data)
{
	t_cylinder	*cy;
	t_color		ratio;

	cy = (t_cylinder *)info.struct_info;
	ratio = ft_find_light_ratio(hit_coord(info.t, camray), data, \
	cylinder_normal(camray, info.t));
	ambient_lightning(&ratio, &data);
	return (ft_color(cy->color.r * ratio.r, cy->color.g * \
	ratio.g, cy->color.b * ratio.b, 0));
}
