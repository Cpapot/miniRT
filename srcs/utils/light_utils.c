/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:55 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:03:18 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "hit.h"
#include "plane.h"

void	*suppress_light(t_light light, t_data *data_pt);
void	delete_hidden_light(t_data *data, t_point point);
void	reset_light(t_data *data);

void	compute_light_ratio(
		t_color *color,
		t_light light,
		double r[2],
		t_material *mat)
{
	color->r += light.color.r * r[0] * 0.004 * light.brightness + \
		mat->specular_coef * r[1];
	color->g += light.color.g * r[0] * 0.004 * light.brightness + \
		mat->specular_coef * r[1];
	color->b += light.color.b * r[0] * 0.004 * light.brightness + \
		mat->specular_coef * r[1];
}

t_vec_3	bounce_vec(t_point hitpoint, t_light light)
{
	t_vec_3	result;

	result.x = light.coordinate.x - hitpoint.x;
	result.y = light.coordinate.y - hitpoint.y;
	result.z = light.coordinate.z - hitpoint.z;
	return (result);
}

void	find_light(t_data *data, double *t, t_ray ray, size_t *index)
{
	double	t_max;
	t_hit	id;

	t_max = 0;
	if (ray.direction.x != 0)
		t_max = (data->lights_arr[*index].coordinate.x - ray.origin.x) \
			/ ray.direction.x;
	else if (ray.direction.y != 0)
		t_max = (data->lights_arr[*index].coordinate.y - ray.origin.y) \
			/ ray.direction.y;
	else if (ray.direction.z != 0)
		t_max = (data->lights_arr[*index].coordinate.z - ray.origin.z) \
			/ ray.direction.z;
	id = find_near_plane(ray, data->pl_nb, data->plane_arr);
	if (id.id != -1)
		*t = plane_hited(ray, data->plane_arr[id.id]);
	if (id.id != -1 && *t != -1 && *t < t_max)
		suppress_light(data->lights_arr[*index], data);
	else
		*index = *index + 1;
}

void	set_data(t_data *data, t_camera *cam)
{
	int						index;
	t_plane					plane;

	index = 0;
	normalize_vec(&cam->vector);
	if (cam->vector.y == 0)
		cam->vector.y = 0.0000001;
	while (data->pl_nb != (size_t)index)
	{
		plane = data->plane_arr[index];
		data->plane_arr[index].normal_vector = plane_normal(cam->vector, plane);
		index++;
	}
	reset_light(data);
	delete_hidden_light(data, cam->origin);
}
