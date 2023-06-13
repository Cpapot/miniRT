/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:13:13 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/13 17:02:05 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
#include "../inc/colors.h"

int32_t	check_ray(t_ray camray, t_minirt_data data)
{
	int			id;
	t_sphere	sp;
	double		dot;
	t_vec_3		lightdir;

	id = find_near_sphere(camray, data.sp_nb, data.sphere_arr);
	if (id == -1)
		return (ft_color(0, 0, 0, 0));
	sp = data.sphere_arr[id];
	lightdir =  data.lights_arr[0].vector;
	if (sphere_hited(camray, sp) != -1)
	{
		dot = ft_find_light(camray.direction , data.lights_arr[0]) / (lightdir.norme * 2);
		return (ft_color(sp.color.r * dot, sp.color.g * dot, sp.color.b * dot, 0));
	}
	return (ft_color(0, 0, 0, 0));
}

