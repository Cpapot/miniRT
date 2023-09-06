/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:13:13 by cpapot            #+#    #+#             */
/*   Updated: 2023/08/01 22:08:10 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "color.h"
#include "hit.h"
#include "light.h"
#include "cone.h"
#include "cylinder.h"
#include "disk.h"

void	find_close_sphere(t_ray camray, t_minirt_data data, t_hitinfo *hit_info)
{
	t_hit	hit;

	hit = find_near_sphere(camray, data.sp_nb, data.sphere_arr);
	if (hit.id != -1)
	{
		hit_info->type = SPHERE;
		hit_info->struct_info = &data.sphere_arr[hit.id];
		hit_info->t = hit.t;
	}
}

void	find_close_plane(t_ray camray, t_minirt_data data, t_hitinfo *info)
{
	t_hit	hit;

	hit = find_near_plane(camray, data.pl_nb, data.plane_arr);
	if (hit.id != -1 && info->t > hit.t)
	{
		info->type = PLANE;
		info->struct_info = &data.plane_arr[hit.id];
		info->t = hit.t;
	}
}

void	find_close_cone(t_ray camray, t_minirt_data data, t_hitinfo *info)
{
	t_hit	hit;

	hit = find_near_cone(camray, data.co_nb, data.cone_arr);
	if (hit.id != -1 && info->t > hit.t)
	{
		info->type = CONE;
		info->struct_info = &data.cone_arr[hit.id];
		info->t = hit.t;
	}
}

void	find_close_cylinder(t_ray camray, t_minirt_data data, t_hitinfo *info)
{
	t_hit	hit;

	hit = find_near_cylinder(camray, data.co_nb, data.cylinder_arr);
	if (hit.id != -1 && info->t > hit.t)
	{
		info->type = CYLINDER;
		info->struct_info = &data.cone_arr[hit.id];
		info->t = hit.t;
	}
}

void	find_close_disk(t_ray camray, t_minirt_data data, t_hitinfo *info)
{
	t_hit	hit;

	hit = find_near_disk(camray, data.di_nb, data.disk_arr);
	if (hit.id != -1 && info->t > hit.t)
	{
		info->type = DISK;
		info->struct_info = &data.disk_arr[hit.id];
		info->t = hit.t;
	}
}

t_hitinfo	find_close_object(t_ray camray, t_minirt_data data)
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

int32_t	check_ray(t_ray camray, t_minirt_data data, int level)
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
		return (render_cone(info, camray, data));
	else if (info.type == CYLINDER)
		return (render_cylinder(info, camray, data, level));
	else if (info.type == DISK)
		return (render_disk(info, camray, data, level));
	return (ft_color(0, 0, 0, 0));
}
