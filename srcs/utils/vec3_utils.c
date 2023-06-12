/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:18:24 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/12 17:08:31 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

t_vec_3	set_vec(double x, double y, double z)
{
	t_vec_3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec_3	vect_product(t_vec_3 vec1, t_vec_3 vec2)
{
	t_vec_3 result;

	result.x = vec1.y * vec2.z - vec1.z * vec2.y;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (result);
}

t_vec_3	adding_vec(t_vec_3 vec1, t_vec_3 vec2)
{
	t_vec_3	vec;

	vec.x = vec1.x + vec2.x;
	vec.y = vec1.y + vec2.y;
	vec.z = vec1.z + vec2.z;
	return (vec);
}

t_vec_3	*multiplying_vec(t_vec_3 *vec, double factor)
{
	vec->x = vec->x * factor;
	vec->y = vec->y * factor;
	vec->z = vec->z * factor;
	return (vec);
}

double	calculate_norm(t_vec_3 *vec)
{
	double	norm;

	norm = sqrt(pow(vec->x, 2) + pow(vec->y, 2) +  pow(vec->z, 2));
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
	double	tmp;

	tmp = calculate_norm(&vec1) * calculate_norm(&vec2);
	result = (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z) / tmp;
	return (result);
}
