/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:29:07 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/19 23:11:46 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_info(t_minirt_data *data)
{
	t_point	pos;
	t_vec_3	dir;

	pos = data->camera[0].origin;
	dir = data->camera[0].vector;
	printf("position : (%f, %f, %f)\n", pos.x, pos.y, pos.z);
	printf("direction : (%f, %f, %f)\n", dir.x, dir.y, dir.z);
	printf("shadow : %d\n", data->option.shadow);
	printf(GREEN"RENDER COMPLETE\n"WHITE);
}
