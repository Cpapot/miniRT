/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:55 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/28 13:03:40 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "hit.h"
#include "plane.h"

void	find_light(t_data *data, double *t, t_ray ray, size_t *index);
void	reset_light(t_data *data);

void	*suppress_light(t_light light, t_data *data_pt)
{
	size_t	lt_nb;

	lt_nb = data_pt->lt_nb;
	while (lt_nb--)
	{
		if (ft_memcmp(&light, &(data_pt->lights_arr[lt_nb]), \
			sizeof(t_light)) == 0)
		{
			data_pt->lt_nb--;
			return (ft_memmove((void *)&(data_pt->lights_arr[lt_nb]), \
				(void *)&(data_pt->lights_arr[lt_nb + 1]), sizeof(t_light) \
					* (data_pt->lt_nb - lt_nb)));
		}
	}
	return (0);
}

void	compute_light(t_color *col, t_light li, double r[2], t_material *mat)
{
	col->r += li.color.r * r[0] * 0.004 * li.brightness + \
		mat->specular_coef * r[1] * li.brightness;
	col->g += li.color.g * r[0] * 0.004 * li.brightness + \
		mat->specular_coef * r[1] * li.brightness;
	col->b += li.color.b * r[0] * 0.004 * li.brightness + \
		mat->specular_coef * r[1] * li.brightness;
}

t_vec_3	bounce_vec(t_point hitpoint, t_light light)
{
	t_vec_3	result;

	result.x = light.coordinate.x - hitpoint.x;
	result.y = light.coordinate.y - hitpoint.y;
	result.z = light.coordinate.z - hitpoint.z;
	return (result);
}

void	delete_hidden_light(t_data *data, t_point point)
{
	size_t	index;
	double	t;
	t_ray	light_ray;

	index = 0;
	t = -1;
	while (data->lt_nb != index)
	{
		light_ray.origin = point;
		light_ray.direction.x = data->lights_arr[index].coordinate.x - point.x;
		light_ray.direction.y = data->lights_arr[index].coordinate.y - point.y;
		light_ray.direction.z = data->lights_arr[index].coordinate.z - point.z;
		normalize_vec(&light_ray.direction);
		find_light(data, &t, light_ray, &index);
	}
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
