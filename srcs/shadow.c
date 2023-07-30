/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:18:34 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/30 13:46:09 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "hit.h"

int	check_shadow(t_point hitpoint, t_light light, t_minirt_data *data)
{
	t_hitinfo	close_object;
	t_ray		bounce_ray;
	double		t_max;

	bounce_ray.direction = set_vec(light.coordinate.x - hitpoint.x, \
	light.coordinate.y - hitpoint.y, light.coordinate.z - hitpoint.z);
	normalize_vec(&bounce_ray.direction);
	bounce_ray.origin = hitpoint;
	t_max = (light.coordinate.x - hitpoint.x) / bounce_ray.direction.x;
	close_object = find_close_object(bounce_ray, *data);
	if (close_object.t >= t_max || close_object.t == -2)
		return (1);
	else
		return (0);
}
