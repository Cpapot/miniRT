/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:49:10 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/28 20:22:06 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	quadratic_equation(double a, double b, double c);

t_vec_3	sphere_normal(t_ray camray, double t, t_point center)
{
	t_point	hitpoint;
	t_vec_3	result;

	hitpoint = hit_coord(t, camray);
	result.x = hitpoint.x - center.x;
	result.y = hitpoint.y - center.y;
	result.z = hitpoint.z - center.z;
	return (result);
}

double	sphere_hited(t_ray ray, t_sphere sphere)
{
	double	A;
	double	B;
	double	C;
	t_vec_3	sphere_vect;

	sphere_vect.x = ray.origin.x - sphere.origin.x;
	sphere_vect.y = ray.origin.y - sphere.origin.y;
	sphere_vect.z = ray.origin.z - sphere.origin.z;
	A = scalar_product(ray.direction, ray.direction);
	B = 2 * scalar_product(ray.direction, sphere_vect);
	C = scalar_product(sphere_vect, sphere_vect) - pow((sphere.diameter) / 2.0, 2);
	return(quadratic_equation(A, B, C));
}

int	find_near_sphere(t_ray camray, size_t count, t_sphere *sphere_arr)
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
		t = sphere_hited(camray, sphere_arr[index]);
		if (tmp > t && (t != -1 || t == -2))
		{
			tmp = t;
			id = index;
		}
		index++;
	}
	return (id);
}

int32_t	render_sphere(t_hitinfo info, t_ray camray, t_minirt_data data)
{
	t_sphere	*sp;
	t_color		ratio;
	t_point		hit;
	double		material[2];

	material[0] = 0.80;
	material[1] = 76.8;
	hit = hit_coord(info.t, camray);
	sp = (t_sphere *)info.struct_info;
	ratio = ft_find_light_ratio(hit, data, \
	sphere_normal(camray, info.t, sp->origin), material);
	ambient_lightning(&ratio, &data);
	return (ft_color(sp->color.r * ratio.r, sp->color.g * \
	ratio.g, sp->color.b * ratio.b, 0));
}
