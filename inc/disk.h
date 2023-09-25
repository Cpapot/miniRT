/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:39:14 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 16:08:21 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISK_H
# define DISK_H

# include "miniRT.h"

t_plane	disk_to_plane(t_disk disk);
double	disk_hited(t_ray ray, t_disk disk);
t_hit	find_near_disk(t_ray camray, size_t count, t_disk *disk_arr);
int32_t	render_disk(t_hitinfo info, t_ray camray, t_data data, int level);

#endif
