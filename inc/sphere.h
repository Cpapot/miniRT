/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:06:01 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/30 21:19:45 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPHERE_H
# define SPHERE_H

#include "hit.h"
#include "color.h"
#include "light.h"

t_point	find_sphere_hit_coord(double dot, t_ray ray);
double	sphere_hited(t_ray ray, t_sphere sphere);
t_hit	find_near_sphere(t_ray camray, size_t count, t_sphere *sphere_arr);
t_vec_3	sphere_normal(t_ray camray, double t, t_point center);
int32_t	render_sphere(t_hitinfo info, t_ray camray, t_minirt_data data, int level);

#endif
