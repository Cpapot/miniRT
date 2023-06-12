/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:49:10 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/12 16:19:09 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	sphere_hited(t_ray ray, t_sphere sphere)
{
	double	A;
	double	B;
	double	C;
	double	delta;

	ray.origin.x = ray.origin.x - sphere.origin.x;
	ray.origin.y = ray.origin.y - sphere.origin.y;
	ray.origin.z = ray.origin.z - sphere.origin.z;
	A = (pow(ray.direction.x, 2) + pow(ray.direction.y, 2) + pow(ray.direction.z, 2));
	B = 2 * (ray.direction.x * ray.origin.x + ray.direction.y * ray.origin.y + ray.direction.z * ray.origin.z);
	C = (pow(ray.origin.x, 2) + pow(ray.origin.y, 2) + pow(ray.origin.z, 2) - pow((sphere.diameter) / 2.0, 2));
	delta = pow(B, 2) - 4 * A * C;
	if (delta >= 0)
		return (1);
	else
		return (0);
}

