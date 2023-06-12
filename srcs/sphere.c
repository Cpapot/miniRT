/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:49:10 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/12 21:48:22 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
		return ((-B - sqrt(delta)) / (2 * 4));
	else
		return (-1);
}

