/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:21:27 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/20 23:14:11 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "hit.h"

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
	return (scalar);
}

void	print_vector(t_vec_3 vector);

void	delete_hidden_light(t_minirt_data *data, t_point point)
{
	size_t	index;
	int		id;
	double	t;
	double	t_max;
	t_ray	light_ray;

	index = 0;
	t = -1;
	while (data->lt_nb != index)
	{
		t_max = 0;
		light_ray.origin = point;
		light_ray.direction.x = data->lights_arr[index].coordinate.x - point.x;
		light_ray.direction.y = data->lights_arr[index].coordinate.y - point.y;
		light_ray.direction.z = data->lights_arr[index].coordinate.z - point.z;
		normalize_vec(&light_ray.direction);
		if (light_ray.direction.x != 0)
			t_max = (data->lights_arr[index].coordinate.x - point.x) / light_ray.direction.x;
		else if (light_ray.direction.y != 0)
			t_max = (data->lights_arr[index].coordinate.y - point.y) / light_ray.direction.y;
		else if (light_ray.direction.z != 0)
			t_max = (data->lights_arr[index].coordinate.z - point.z) / light_ray.direction.z;
		id = find_near_plane(light_ray, data->pl_nb, data->plane_arr);
		if (id != -1)
			t = plane_hited(light_ray, data->plane_arr[id]);
		if (id != -1 && t != -1 && t < t_max)
		{
			printf("light deleted :%ld\n", index);
			index++;
		}
		else
			index++;
	}
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
		hitpoint.x = hitpoint.x + (normal.x * 0.0001);
		hitpoint.y = hitpoint.y + (normal.y * 0.0001);
		hitpoint.z = hitpoint.z + (normal.z * 0.0001);
		ratio = check_intersection(light, hitpoint, normal);
		if (!data.option.shadow || check_shadow(hitpoint, light, &data))
		{
			result.r += light.color.r * ratio * 0.004 * light.brightness;
			result.g += light.color.g * ratio * 0.004 * light.brightness;
			result.b += light.color.b * ratio * 0.004 * light.brightness;
		}
		index++;
	}
	return (result);
}
