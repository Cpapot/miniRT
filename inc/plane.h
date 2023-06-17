/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:06:53 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/17 02:20:59 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

double	plane_hited(t_ray ray, t_plane plane);
int		find_near_plane(t_ray camray, size_t count, t_plane *plane_arr);
t_vec_3	plane_normal(t_vec_3 camdir, t_plane plane);

#endif
