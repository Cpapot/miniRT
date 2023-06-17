/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:21:27 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/17 02:23:33 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#include "hit.h"
double	check_shadow(t_vec_3 bounce_vec, t_point hitpoint, t_light light, t_minirt_data data);

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

double	check_intersection(t_light light, t_point hitpoint, t_vec_3 normal)
{
	t_vec_3	bounce;
	double	scalar;

	bounce = bounce_vec(hitpoint, light);
	normalize_vec(&bounce);
	scalar = scalar_product(bounce, normal);
	if (scalar < 0)
		scalar = 0;
	//scalar = check_shadow(bounce, hitpoint, light, data);
	return (scalar);
}

t_color	ft_find_light_ratio(t_point hitpoint, t_minirt_data data, t_vec_3 normal)
{
	size_t	index;
	t_color	result;
	t_light	light;
	double	ratio;

	result.r = 0;
	result.g = 0;
	result.b = 0;
	index = 0;
	while (data.lt_nb != index)
	{
		light = data.lights_arr[index];
		ratio = check_intersection(light, hitpoint, normal);
		result.r += light.color.r * ratio * 0.01 * light.brightness;
		result.g += light.color.g * ratio * 0.01 * light.brightness;
		result.b += light.color.b * ratio * 0.01 * light.brightness;
		index++;
	}
	return (result);
}
