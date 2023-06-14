/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:01:59 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/14 15:51:28 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

double	plane_hited(t_ray ray, t_plane plane)
{
	double	d;
	double	t;
	t_vec_3	origin;

	d = -(plane.normal_vector.x * plane.coordinate.x + plane.normal_vector.y \
	* plane.coordinate.y + plane.normal_vector.z * plane.coordinate.z);
	origin.x = ray.origin.x;
	origin.y = ray.origin.y;
	origin.z = ray.origin.z;
	t = -(scalar_product(plane.normal_vector, origin) + d) \
		/ scalar_product(plane.normal_vector, ray.direction);
	if (t > 0)
		return (t);
	else
		return (-1);
}
