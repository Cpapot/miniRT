/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:18:24 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/09 14:55:11 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_vec_3	*scalar_product(t_vec_3 *vec1, t_vec_3 *vec2)
{
	t_vec_3 *result;

	result->x = vec1->y * vec2->z - vec1->z * vec2->y;
	result->y = vec1->z * vec2->x - vec1->x * vec2->z;
	result->z = vec1->x * vec2->y - vec1->y * vec2->x;
	return (result);
}

t_vec_3	*multiplying_vec(t_vec_3 *vec, double fac)
{
	vec->x = vec->x * fac;
	vec->y = vec->y * fac;
	vec->z = vec->z * fac;
	return (vec);
}

double	calculate_norm(t_vec_3 *vec)
{
	double	norm;

	norm = sqrt(pow(vec->x, 2) + pow(vec->y, 2) +  pow(vec->z, 2));
	vec->norme = norm;
	return (norm);
}
