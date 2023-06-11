/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:26:57 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/11 13:27:51 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VEC3_H
# define VEC3_H

#include "miniRT.h"

t_vec_3		adding_vec(t_vec_3 vec1, t_vec_3 vec2);
t_vec_3		set_vec(double x, double y, double z);
t_vec_3		scalar_product(t_vec_3 vec1, t_vec_3 vec2);
t_vec_3		*multiplying_vec(t_vec_3 *vec, double factor);
double		calculate_norm(t_vec_3 *vec);
void		normalize_vec(t_vec_3 *vec);

#endif
