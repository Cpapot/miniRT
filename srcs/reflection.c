/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:37:21 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/24 16:43:16 by cpapot           ###   ########.fr       */
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

int32_t	reflection(int32_t light, t_data data, t_ray camray, t_material *mat)
{
	double		reflection;
	t_color		light_color;
	t_color		reflect_color;

	if (!mat)
		reflection = 0.4;
	else
		reflection = mat->reflection;
	if (data.level == 10 || reflection == 0)
		return (light);
	light_color = int_to_rgb(light);
	reflect_color = int_to_rgb(check_ray(camray, data, data.level + 1));
	return (ft_color(reflect_color.r * reflection + light_color.r * \
		(1 - reflection), reflect_color.g * reflection + light_color.g * \
		(1 - reflection), reflect_color.b * reflection + light_color.b * \
		(1 - reflection), 0));
}
