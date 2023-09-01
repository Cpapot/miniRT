/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:23:07 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/01 15:45:34 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H

# define CONE_H
# include "structure.h"

double		cone_hitted(t_ray camray, t_cone cone);
t_hit		find_near_cone(t_ray camray, size_t count, t_cone *cone_arr);
t_vec_3		cone_normal(t_ray camray, double t, t_cone cone);
int32_t		render_cone(t_hitinfo info, t_ray camray, t_minirt_data data, int level);

#endif
