/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:21:27 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/30 05:01:25 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "hit.h"

void	*suppress_light(t_light light, t_minirt_data *data_pt);

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

void	delete_hidden_light(t_minirt_data *data, t_point point)
{
	size_t	index;
	t_hit	id;
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
		if (id.id != -1)
			t = plane_hited(light_ray, data->plane_arr[id.id]);
		if (id.id != -1 && t != -1 && t < t_max)
			suppress_light(data->lights_arr[index], data);
		else
			index++;
	}
}

double	specular_light_ratio(t_vec_3 light_dir, t_vec_3 normal, double mat[2])
{
	t_vec_3	view_vec;
	double	result;

	normalize_vec(&light_dir);
	view_vec = normal;
	multiplying_vec(&view_vec, 2 * (-scalar_product(normal, light_dir)));
	view_vec = adding_vec(view_vec, light_dir);
	normalize_vec(&view_vec);
	result = -scalar_product(view_vec, light_dir);
	if (result < 0)
		result = 0;
	result = pow(result, mat[1]);
	return (result);
}
t_color	ft_find_light_ratio(t_point hitpoint, t_minirt_data data, t_vec_3 normal, double mat[3])
{
	size_t	index;
	t_color	result;
	t_light	light;
	double	ratio[2];

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
		ratio[1] = specular_light_ratio(set_vec(hitpoint.x - light.coordinate.x, \
		hitpoint.y - light.coordinate.y, hitpoint.z - light.coordinate.z), normal, mat);
		ratio[0] = check_intersection(light, hitpoint, normal);
		if (!data.option.shadow || check_shadow(hitpoint, light, &data))
		{
			result.r += light.color.r * ratio[0] * 0.004 * light.brightness + mat[0] * ratio[1];
			result.g += light.color.g * ratio[0] * 0.004 * light.brightness + mat[0] * ratio[1];
			result.b += light.color.b * ratio[0] * 0.004 * light.brightness + mat[0] * ratio[1];
		}
		index++;
	}
	return (result);
}
