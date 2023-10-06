/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:18:24 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/20 16:25:33 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec_3	set_vec(double x, double y, double z)
{
	t_vec_3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

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
