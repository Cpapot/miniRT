/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:15:19 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/21 14:12:19 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

void		ambient_lightning(t_color *ratio, t_data *data);
int			check_shadow(t_point hitpoint, t_light light, t_data *data);
t_hitinfo	find_close_object(t_ray camray, t_data data);

#endif
