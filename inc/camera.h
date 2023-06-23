/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:10:40 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/23 17:16:33 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "miniRT.h"

t_ray	find_camray(t_camera cam_info, int x, int y);
int32_t	anti_aliasing(t_minirt_data *data, int x, int y, t_camera cam);
t_ray	find_aliasing_ray(t_camera cam_info, int x, int y, int index);

#endif
