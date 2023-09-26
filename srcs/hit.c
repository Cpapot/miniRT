/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:13:13 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/26 19:51:21 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "color.h"
#include "find_object.h"
#include "light.h"
#include "plane.h"
#include "sphere.h"
#include "cone.h"
#include "cylinder.h"
#include "disk.h"

t_hitinfo	find_close_object(t_ray camray, t_data data)
{
	t_hitinfo	info;

	info.t = INT_MAX;
	info.type = -1;
	find_close_sphere(camray, data, &info);
	find_close_plane(camray, data, &info);
	find_close_cone(camray, data, &info);
	find_close_cylinder(camray, data, &info);
	find_close_disk(camray, data, &info);
	return (info);
}

int32_t	check_ray(t_ray camray, t_data data, int level)
{
	t_hitinfo	info;

	info = find_close_object(camray, data);
	if (info.type == -1 || info.t == -2)
		return (ft_color(0, 0, 0, 0));
	else if (info.type == SPHERE)
		return (render_sphere(info, camray, data, level));
	else if (info.type == PLANE)
		return (render_plane(info, camray, data, level));
	else if (info.type == CONE)
		return (render_cone(info, camray, data, level));
	else if (info.type == CYLINDER)
		return (render_cylinder(info, camray, data, level));
	else if (info.type == DISK)
		return (render_disk(info, camray, data, level));
	return (ft_color(0, 0, 0, 0));
}
