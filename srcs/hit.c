/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:13:13 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/19 20:25:23 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
#include "../inc/color.h"
#include "../inc/hit.h"

double	check_shadow(t_vec_3 bounce_vec, t_point hitpoint, t_light light, t_minirt_data data);

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
	if (tmp != -1 && info.t > plane_hited(camray, data.plane_arr[tmp]))
	{
		info.type = PLANE;
		info.struct_info =  &data.plane_arr[tmp];
		info.t = plane_hited(camray, data.plane_arr[tmp]);
	}
	return (info);
}

int32_t	check_ray(t_ray camray, t_minirt_data data)
{
	t_hitinfo	info;
	t_plane		*pl;
	t_sphere	*sp;
	t_color		color_ratio;

	info = find_close_object(camray, data);
	if (info.type == -1 || info.t == -2)
		return (ft_color(0, 0, 0, 0));
	else if (info.type == SPHERE)
	{
		sp = (t_sphere *)info.struct_info;
		color_ratio = ft_find_light_ratio(hit_coord(info.t, camray), data, sphere_normal(camray, info.t, sp->origin));
		ambient_lightning(&color_ratio, &data);
		return (ft_color(sp->color.r * color_ratio.r, sp->color.g * color_ratio.g, sp->color.b * color_ratio.b, 0));
	}
	else if (info.type == PLANE)
	{
		pl = (t_plane *)info.struct_info;
		color_ratio = ft_find_light_ratio(hit_coord(info.t, camray), data, pl->normal_vector);
		ambient_lightning(&color_ratio, &data);
		return (ft_color(pl->color.r * color_ratio.r, pl->color.g * color_ratio.g, pl->color.b * color_ratio.b, 0));
	}
	return (ft_color(0, 0, 0, 0));
}
