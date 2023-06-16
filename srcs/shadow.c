/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:18:34 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/16 14:47:29 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "hit.h"

t_hitinfo	find_close_object(t_ray camray, t_minirt_data data);

double	check_shadow(t_vec_3 bounce_vec, t_point hitpoint, t_light light, t_minirt_data data)
{
	t_hitinfo	close_object;
	t_ray		bounce_ray;
	double		t_max;

	bounce_ray.direction = bounce_vec;
	bounce_ray.origin = hitpoint;
	t_max = (light.coordinate.x - hitpoint.x)/bounce_vec.x;
	close_object = find_close_object(bounce_ray, data);
	if (close_object.t >= t_max)
		return (1);
	else
		return (0);
}
