/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:23:07 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/20 16:23:46 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec_3	vect_product(t_vec_3 vec1, t_vec_3 vec2)
{
	t_vec_3	result;

	result.x = vec1.y * vec2.z - vec1.z * vec2.y;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (result);
}

t_vec_3	minus_vec(t_vec_3 vec1, t_vec_3 vec2)
{
	t_vec_3	vec;

	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	vec.z = vec1.z - vec2.z;
	return (vec);
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

t_vec_3	multip_vec(t_vec_3 vec, double factor)
{
	vec.x = vec.x * factor;
	vec.y = vec.y * factor;
	vec.z = vec.z * factor;
	return (vec);
}
