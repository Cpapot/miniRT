/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:49:10 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/19 16:49:59 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	double	delta;
	t_vec_3	sphere_vect;

	sphere_vect.x = ray.origin.x - sphere.origin.x;
	sphere_vect.y = ray.origin.y - sphere.origin.y;
	sphere_vect.z = ray.origin.z - sphere.origin.z;
	A = scalar_product(ray.direction, ray.direction);
	B = 2 * scalar_product(ray.direction, sphere_vect);
	C = scalar_product(sphere_vect, sphere_vect) - pow((sphere.diameter) / 2.0, 2);
	delta = pow(B, 2) - 4 * A * C;
	if (delta >= 0)
	{
		if (((-B - sqrt(delta)) / (2 * A)) > 0)
			return ((-B - sqrt(delta)) / (2 * A));
		else if (((-B + sqrt(delta)) / (2 * A)) > 0)
			return ((-B + sqrt(delta)) / (2 * A));
		else
			return (-1);
	}
		return (-1);
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
		if (tmp > t && t != -1)
		{
			tmp = t;
			id = index;
		}
		index++;
	}
	return (id);
}
