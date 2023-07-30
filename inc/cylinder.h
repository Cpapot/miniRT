/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:18:04 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/30 02:29:34 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H

# define CYLINDER_H
# include "structure.h"

t_vec_3		cylinder_normal(t_ray camray);
double		cylinder_hitted(t_ray camray, t_cylinder cyl);
t_hit		find_near_cylinder(t_ray camray, size_t count, t_cylinder *cyl_arr);
int32_t		render_cylinder(t_hitinfo info, t_ray camray, t_minirt_data data);

#endif
