/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:25:04 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/23 18:04:07 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	scalar_product(t_vec_3 vec1, t_vec_3 vec2)
{
	double	result;

	result = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	return (result);
}

t_point	hit_coord(double dot, t_ray ray)
{
	t_point	result;

	result.x = ray.origin.x + ray.direction.x * dot;
	result.y = ray.origin.y + ray.direction.y * dot;
	result.z = ray.origin.z + ray.direction.z * dot;
	return (result);
}

t_point	adjust_hitpoint(t_point hit, t_vec_3 normal)
{
	hit.x = hit.x + (normal.x * 0.0005);
	hit.y = hit.y + (normal.y * 0.0005);
	hit.z = hit.z + (normal.z * 0.0005);
	return (hit);
}
