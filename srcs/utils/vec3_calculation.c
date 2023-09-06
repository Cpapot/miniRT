/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:18:24 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/30 19:16:52 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	calculate_norm(t_vec_3 *vec)
{
	double	norm;

	norm = sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2));
	vec->norme = norm;
	return (norm);
}

void	normalize_vec(t_vec_3 *vec)
{
	double	norm;

	norm = calculate_norm(vec);
	vec->x = vec->x / norm;
	vec->y = vec->y / norm;
	vec->z = vec->z / norm;
}

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
	hit.x = hit.x + (normal.x * 0.0001);
	hit.y = hit.y + (normal.y * 0.0001);
	hit.z = hit.z + (normal.z * 0.0001);
	return (hit);
}
