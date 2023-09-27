/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:45:27 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/26 19:46:06 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "light.h"
#include "plane.h"
#include "sphere.h"
#include "cone.h"
#include "cylinder.h"
#include "disk.h"
#include "miniRT.h"

void	find_close_sphere(t_ray camray, t_data data, t_hitinfo *info)
{
	t_hit	hit;

	hit = find_near_sphere(camray, data.sp_nb, data.sphere_arr);
	if (hit.id != -1)
	{
		info->type = SPHERE;
		info->struct_info = &data.sphere_arr[hit.id];
		info->t = hit.t;
		info->inside = hit.inside;
	}
}

void	find_close_plane(t_ray camray, t_data data, t_hitinfo *info)
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

void	find_close_cone(t_ray camray, t_data data, t_hitinfo *info)
{
	t_hit	hit;

	hit = find_near_cone(camray, data.co_nb, data.cone_arr);
	if (hit.id != -1 && info->t > hit.t)
	{
		info->type = CONE;
		info->struct_info = &data.cone_arr[hit.id];
		info->t = hit.t;
		info->inside = hit.inside;
	}
}

void	find_close_cylinder(t_ray camray, t_data data, t_hitinfo *info)
{
	t_hit	hit;

	hit = find_near_cylinder(camray, data.cy_nb, data.cylinder_arr);
	if (hit.id != -1 && info->t > hit.t)
	{
		info->type = CYLINDER;
		info->struct_info = &data.cylinder_arr[hit.id];
		info->t = hit.t;
		info->inside = hit.inside;
	}
}

void	find_close_disk(t_ray camray, t_data data, t_hitinfo *info)
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
