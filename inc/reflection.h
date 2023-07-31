/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:27:15 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/31 22:28:00 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECTION_H
# define REFLECTION_H

#include "miniRT.h"

t_vec_3	reflect_vec(t_vec_3 normal, t_vec_3 ray);
int32_t	reflection(int32_t light, t_minirt_data data, t_ray camray, int level);

#endif
