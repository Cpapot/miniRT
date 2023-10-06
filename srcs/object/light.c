/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:21:27 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/28 12:48:38 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "hit.h"
#include "light.h"
#include "color.h"
#include "plane.h"

void	compute_light(t_color *col, t_light li, double r[2], t_material *mat);
t_vec_3	bounce_vec(t_point hitpoint, t_light light);
void	*suppress_light(t_light light, t_data *data_pt);

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

double	specular_light(t_vec_3 light_dir, t_vec_3 normal, t_material *mat)
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
	result = pow(result, mat->alpha);
	return (result);
}

t_color	light_ratio(t_point p, t_data data, t_vec_3 normal, t_material *mat)
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
		p.x = p.x + (normal.x * 0.0001);
		p.y = p.y + (normal.y * 0.0001);
		p.z = p.z + (normal.z * 0.0001);
		ratio[1] = specular_light(set_vec(p.x - light.coordinate.x, p.y \
			- light.coordinate.y, p.z - light.coordinate.z), normal, mat);
		ratio[0] = check_intersection(light, p, normal);
		if (!data.option.shadow || check_shadow(p, light, &data))
			compute_light(&result, light, ratio, mat);
		index++;
	}
	return (result);
}

void	reset_light(t_data *data)
{
	static t_light			first_data[LIGHT_BUFF];
	int						i;
	static int				index = 0;
	static int				lt_nb;

	i = 0;
	if (index == 0)
	{
		lt_nb = data->lt_nb;
		while (i != lt_nb && i != LIGHT_BUFF)
		{
			first_data[i] = data->lights_arr[i];
			i++;
		}
	}
	else
	{
		data->lt_nb = lt_nb;
		while (i != lt_nb && i != LIGHT_BUFF)
		{
			data->lights_arr[i] = first_data[i];
			i++;
		}
	}
	index++;
}
