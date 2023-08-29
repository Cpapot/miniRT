/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:54:31 by cpapot            #+#    #+#             */
/*   Updated: 2023/08/29 17:29:47 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"
#include "checkerboard.h"
#include "reflection.h"

double	quadratic_equation(double a, double b, double c);

t_vec_3 cylinder_normal(t_ray camray, double t, t_cylinder cyl)
{
	t_vec_3	result;
	double	scalar;
	t_point	hit;
	t_vec_3	dot;
	t_vec_3	vec[2];

	hit = hit_coord(t, camray);
	dot = set_vec(hit.x, hit.y, hit.z);
	normalize_vec(&dot);
	vec[0] = set_vec(dot.x - cyl.coordinate.x, dot.y - cyl.coordinate.y, dot.z - cyl.coordinate.z);
	scalar = scalar_product(vec[0], cyl.normal_vector);
	vec[1] = set_vec(cyl.coordinate.x + scalar * cyl.normal_vector.x, cyl.coordinate.y + scalar * cyl.normal_vector.y, cyl.coordinate.z + scalar * cyl.normal_vector.z);
	result = set_vec(dot.x - vec[1].x, dot.y - vec[1].y, dot.z - vec[1].z);
	normalize_vec(&result);
	return (result);
}

double	cylinder_hitted(t_ray camray, t_cylinder cyl)
{
	double	A;
	double	B;
	double	C;
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
	t = quadratic_equation(A, B, C);
	hitpoint = hit_coord(t, camray);
	vec = set_vec(cyl.coordinate.x - hitpoint.x,cyl.coordinate.y - hitpoint.y, cyl.coordinate.z - hitpoint.z);
	if (!(scalar_product(cyl.normal_vector, vec) >= 0 && scalar_product(cyl.normal_vector, vec) <= cyl.height))
		return (-1);
	return (t);
}

t_hit		find_near_cylinder(t_ray camray, size_t count, t_cylinder *cyl_arr)
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
	hit = adjust_hitpoint(hit_coord(info.t, camray), cylinder_normal(camray, info.t, *cy));
	//if (is_black_case(hit))
	//	return (ft_color(0, 0, 0, 0));
	ratio = ft_find_light_ratio(hit, data, \
	cylinder_normal(camray, info.t, *cy), &cy->material);
	ambient_lightning(&ratio, &data);
	reflect_ray.direction = reflect_vec(cylinder_normal(camray, info.t, *cy), camray.direction);
	reflect_ray.origin = hit;
	return (reflection(ft_color(cy->color.r * ratio.r, cy->color.g * \
		ratio.g, cy->color.b * ratio.b, 0), data, reflect_ray, level, &cy->material));
}
