/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:15:19 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/26 21:53:33 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "miniRT.h"

void		ambient_lightning(t_color *ratio, t_data *data);
int			check_shadow(t_point hitpoint, t_light light, t_data *data);
t_hitinfo	find_close_object(t_ray camray, t_data data);

#endif
