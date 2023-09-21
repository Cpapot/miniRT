/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:30:44 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/21 13:55:39 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H

# define LIGHT_H

#include "structure.h"

void	delete_hidden_light(t_data *data, t_point point);
t_vec_3	bounce_vec(t_point hitpoint, t_light light);
double	check_intersection(t_light light, t_point hitpoint, t_vec_3 normal);
t_color	ft_find_light_ratio(t_point hitpoint, t_data data, t_vec_3 normal, t_material *mat);

# ifndef LIGHT_BUFF
#  define LIGHT_BUFF 2048
# endif

#endif
