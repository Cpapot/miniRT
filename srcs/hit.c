/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:13:13 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/17 00:50:10 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
#include "../inc/color.h"
#include "../inc/hit.h"

t_hitinfo	find_close_object(t_ray camray, t_minirt_data data)
{
	int			tmp;
	t_hitinfo	info;

	info.t = INT_MAX;
	info.type = -1;
	tmp = find_near_sphere(camray, data.sp_nb, data.sphere_arr);
	if (tmp != -1)
	{
		info.type = SPHERE;
		info.struct_info = &data.sphere_arr[tmp];
		info.t = sphere_hited(camray, data.sphere_arr[tmp]);
	}
	tmp = find_near_plane(camray, data.pl_nb, data.plane_arr);
	if (tmp != -1 && info.t > plane_hited(camray, data.plane_arr[tmp], 0))
	{
		info.type = PLANE;
		info.struct_info =  &data.plane_arr[tmp];
		info.t = plane_hited(camray, data.plane_arr[tmp], 0);
	}
	return (info);
}

int32_t	check_ray(t_ray camray, t_minirt_data data)
{
	t_hitinfo	info;
	t_plane		*pl;
	t_sphere	*sp;
	double		dot;

	dot = 1;
	info = find_close_object(camray, data);
	if (info.type == -1)
		return (ft_color(0, 0, 0, 0));
	else if (info.type == SPHERE)
	{
		sp = (t_sphere *)info.struct_info;
		dot = ft_find_light_ratio(hit_coord(info.t, camray), data, sphere_normal(camray, info.t, sp->origin));
		return (ft_color(sp->color.r * dot, sp->color.g * dot, sp->color.b * dot, 0));
	}
	else if (info.type == PLANE)
	{
		pl = (t_plane *)info.struct_info;
		dot = ft_find_light_ratio(hit_coord(info.t, camray), data, pl->normal_vector);
		if (dot <= 0)
		{
			multiplying_vec(&pl->normal_vector, -1);
			dot = ft_find_light_ratio(hit_coord(info.t, camray), data, pl->normal_vector);
		}
		return (ft_color(pl->color.r * dot, pl->color.g * dot, pl->color.b * dot, 0));
	}
	return (ft_color(0, 0, 0, 0));
}
