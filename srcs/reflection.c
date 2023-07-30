/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:37:21 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/30 21:12:10 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "vec3.h"

t_vec_3	reflect_vec(t_vec_3 normal, t_vec_3 ray)
{
	t_vec_3	result;

	result.x = ray.x - 2 * scalar_product(ray, normal) * normal.x;
	result.y = ray.y - 2 * scalar_product(ray, normal) * normal.y;
	result.z = ray.z - 2 * scalar_product(ray, normal) * normal.z;
	normalize_vec(&result);
	return (result);
}


