/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:21:27 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/16 15:58:12 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// double	ft_find_light(t_vec_3 normal, t_light light)
// {
// 	double	dot;

// 	dot = scalar_product(normal, light.vector);
// 	if (dot <= 0)
// 		dot = 0;
// 	return (dot);
// }

t_vec_3	bounce_vec(t_point hitpoint, t_light light)
{
	t_vec_3	result;

	result.x = light.coordinate.x - hitpoint.x;
	result.y = light.coordinate.y - hitpoint.y;
	result.z = light.coordinate.z - hitpoint.z;
	return (result);
}
//scalaire entre la norme du cercle et le rayon rebondie
double	check_intersection(t_light light, t_point hitpoint, t_vec_3 normal)
{
	t_vec_3	bounce;
	double	scalar;

	bounce = bounce_vec(hitpoint, light);
	normalize_vec(&bounce);
	scalar = scalar_product(bounce, normal);
	if (scalar < 0)
		scalar = 0;
	return (scalar);
}

double	ft_find_light_ratio(t_point hitpoint, t_minirt_data data, t_vec_3 normal)
{
	size_t	index;
	t_light	light;
	double	result;

	result = 0;
	index = 0;
	while (data.lt_nb != index)
	{
		light = data.lights_arr[index];
		result += check_intersection(light, hitpoint, normal);
		index++;
	}
	result = 1;
	return (result);
}
