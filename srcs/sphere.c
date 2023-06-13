/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:49:10 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/13 16:48:56 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	find_sphere_hit_coord(double dot, t_ray ray)
{
	t_point	result;

	result.x = ray.origin.x + ray.direction.x * dot;
	result.y = ray.origin.y + ray.direction.y * dot;
	result.z = ray.origin.z + ray.direction.z * dot;
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
		return ((-B - sqrt(delta)) / (2 * A));
	else
		return (-1);
}

int	find_near_sphere(t_ray camray, size_t count, t_sphere *sphere_arr)
{
	size_t	index;
	double	tmp;
	int		id;

	id = -1;
	index = 0;
	while (index != count)
	{
		if (index == 0)
		{
			tmp = sphere_hited(camray, sphere_arr[index]);
			id = index;
		}
		if (tmp > sphere_hited(camray, sphere_arr[index]))
		{
			tmp = sphere_hited(camray, sphere_arr[index]);
			id = index;
		}
		index++;
	}
	return (id);
}
