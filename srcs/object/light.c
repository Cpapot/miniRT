/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:21:27 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/24 16:44:41 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "hit.h"

void	find_light(t_data *data, double *t, t_ray ray, size_t *index);
void	compute_light_ratio(t_color *color, t_light light, double r[2], t_material *mat);
t_vec_3	bounce_vec(t_point hitpoint, t_light light);

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

t_color	ft_find_light_ratio(t_point point, t_data data, t_vec_3 normal, t_material *mat)
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
		point.x = point.x + (normal.x * 0.0001);
		point.y = point.y + (normal.y * 0.0001);
		point.z = point.z + (normal.z * 0.0001);
		ratio[1] = specular_light(set_vec(point.x - light.coordinate.x, point.y \
			- light.coordinate.y, point.z - light.coordinate.z), normal, mat);
		ratio[0] = check_intersection(light, point, normal);
		if (!data.option.shadow || check_shadow(point, light, &data))
			compute_light_ratio(&result, light, ratio, mat);
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
