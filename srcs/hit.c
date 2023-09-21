/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:13:13 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/21 13:55:39 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "color.h"
#include "hit.h"
#include "light.h"
#include "cone.h"
#include "cylinder.h"
#include "disk.h"

t_hitinfo	find_close_object(t_ray camray, t_data data)
{
	t_hitinfo	info;
	t_hit		hit;

	info.t = INT_MAX;
	info.type = -1;
	hit = find_near_sphere(camray, data.sp_nb, data.sphere_arr);
	if (hit.id != -1)
	{
		info.type = SPHERE;
		info.struct_info = &data.sphere_arr[hit.id];
		info.t = hit.t;
	}
	hit = find_near_plane(camray, data.pl_nb, data.plane_arr);
	if (hit.id != -1 && info.t > hit.t)
	{
		info.type = PLANE;
		info.struct_info = &data.plane_arr[hit.id];
		info.t = hit.t;
	}
	hit = find_near_cone(camray, data.co_nb, data.cone_arr);
	if (hit.id != -1 && info.t > hit.t)
	{
		info.type = CONE;
		info.struct_info = &data.cone_arr[hit.id];
		info.t = hit.t;
	}
	hit = find_near_cylinder(camray, data.cy_nb, data.cylinder_arr);
	if (hit.id != -1 && info.t > hit.t)
	{
		info.type = CYLINDER;
		info.struct_info = &data.cylinder_arr[hit.id];
		info.t = hit.t;
	}
	hit = find_near_disk(camray, data.di_nb, data.disk_arr);
	if (hit.id != -1 && info.t > hit.t)
	{
		info.type = DISK;
		info.struct_info = &data.disk_arr[hit.id];
		info.t = hit.t;
	}
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
