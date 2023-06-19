/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:00:33 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/19 23:10:21 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "../inc/key.h"

void	screen_loop(t_mlx_info *win, t_minirt_data *data);

int	close_window(void)
{
	exit(EXIT_SUCCESS);
}

int	deal_key(int key, t_general *info)
{
	t_vec_3	movement;

	if (key == KB_UP)
	{
		movement = set_vec(0, 0.10, 0);
		info->data.camera[0].vector = adding_vec(info->data.camera[0].vector, movement);
		normalize_vec(&info->data.camera[0].vector);
	}
	else if (key == KB_DOWN)
	{
		movement = set_vec(0, -0.10, 0);
		info->data.camera[0].vector = adding_vec(info->data.camera[0].vector, movement);
		normalize_vec(&info->data.camera[0].vector);
	}
	else if (key == KB_LEFT)
	{
		movement = set_vec(-0.10, 0, 0);
		info->data.camera[0].vector = adding_vec(info->data.camera[0].vector, movement);
		normalize_vec(&info->data.camera[0].vector);
	}
	else if (key == KB_RIGHT)
	{
		movement = set_vec(0.10, 0, 0);
		info->data.camera[0].vector = adding_vec(info->data.camera[0].vector, movement);
		normalize_vec(&info->data.camera[0].vector);
	}
	else if (key == KB_W)
	{
		movement = info->data.camera[0].vector;
		info->data.camera[0].origin.x += movement.x;
		info->data.camera[0].origin.y += movement.y;
		info->data.camera[0].origin.z += movement.z;
	}
	else if (key == KB_S)
	{
		movement = info->data.camera[0].vector;
		info->data.camera[0].origin.x -= movement.x;
		info->data.camera[0].origin.y -= movement.y;
		info->data.camera[0].origin.z -= movement.z;
	}
	else if (key == KP_1)
		info->data.option.shadow = !info->data.option.shadow ;
	else if (key == KB_ESC || key == 17)
		exit(0);
	screen_loop(&info->win, &info->data);
	return (1);
}
