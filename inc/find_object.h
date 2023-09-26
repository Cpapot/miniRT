/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:46:22 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/26 19:50:35 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_OBJECT_H
# define FIND_OBJECT_H

# include "miniRT.h"

void	find_close_sphere(t_ray camray, t_data data, t_hitinfo *info);
void	find_close_plane(t_ray camray, t_data data, t_hitinfo *info);
void	find_close_cone(t_ray camray, t_data data, t_hitinfo *info);
void	find_close_cylinder(t_ray camray, t_data data, t_hitinfo *info);
void	find_close_disk(t_ray camray, t_data data, t_hitinfo *info);


#endif
