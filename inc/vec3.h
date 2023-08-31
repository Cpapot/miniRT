/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:26:57 by cpapot            #+#    #+#             */
/*   Updated: 2023/08/31 18:34:29 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VEC3_H
# define VEC3_H

#include "miniRT.h"

t_vec_3		adding_vec(t_vec_3 vec1, t_vec_3 vec2);
t_vec_3		set_vec(double x, double y, double z);
t_vec_3		vect_product(t_vec_3 vec1, t_vec_3 vec2);
t_vec_3		*multiplying_vec(t_vec_3 *vec, double factor);
double		calculate_norm(t_vec_3 *vec);
void		normalize_vec(t_vec_3 *vec);
double		scalar_product(t_vec_3 vec1, t_vec_3 vec2);
t_point		hit_coord(double dot, t_ray ray);
t_point		adjust_hitpoint(t_point hit, t_vec_3 normal);
t_vec_3		minus_vec(t_vec_3 vec1, t_vec_3 vec2);
t_vec_3		multip_vec(t_vec_3 vec, double factor);

#endif
