/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:06:01 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/13 13:06:59 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPHERE_H
# define SPHERE_H

t_point	find_sphere_hit_coord(double dot, t_ray ray);
double	sphere_hited(t_ray ray, t_sphere sphere);


#endif
