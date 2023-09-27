/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:22:36 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/27 02:32:10 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOSE_H
# define CLOSE_H

#include "miniRT.h"
#include "camera.h"

void	destroy_image_arr(t_mlx_info *win, t_data *data);
int		clean_minirt_data(t_data *data_pt);
void	close_minirt(t_mlx_info *win, t_data *data, int status);

#endif
