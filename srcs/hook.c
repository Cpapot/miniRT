/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:00:33 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/21 13:55:39 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "../inc/key.h"

void	screen_loop(t_mlx_info *win, t_data *data);

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
		info->data.camera[info->data.option.cam_id].vector = adding_vec(info->data.camera[info->data.option.cam_id].vector, movement);
		normalize_vec(&info->data.camera[info->data.option.cam_id].vector);
	}
	else if (key == KB_DOWN)
	{
		movement = set_vec(0, -0.10, 0);
		info->data.camera[info->data.option.cam_id].vector = adding_vec(info->data.camera[info->data.option.cam_id].vector, movement);
		normalize_vec(&info->data.camera[info->data.option.cam_id].vector);
	}
	else if (key == KB_LEFT)
	{
		movement = set_vec(-0.10, 0, 0);
		info->data.camera[info->data.option.cam_id].vector = adding_vec(info->data.camera[info->data.option.cam_id].vector, movement);
		normalize_vec(&info->data.camera[info->data.option.cam_id].vector);
	}
	else if (key == KB_RIGHT)
	{
		movement = set_vec(0.10, 0, 0);
		info->data.camera[info->data.option.cam_id].vector = adding_vec(info->data.camera[info->data.option.cam_id].vector, movement);
		normalize_vec(&info->data.camera[info->data.option.cam_id].vector);
	}
	else if (key == KB_W)
	{
		movement = info->data.camera[info->data.option.cam_id].vector;
		info->data.camera[info->data.option.cam_id].origin.x += movement.x;
		info->data.camera[info->data.option.cam_id].origin.y += movement.y;
		info->data.camera[info->data.option.cam_id].origin.z += movement.z;
	}
	else if (key == KB_S)
	{
		movement = info->data.camera[info->data.option.cam_id].vector;
		info->data.camera[info->data.option.cam_id].origin.x -= movement.x;
		info->data.camera[info->data.option.cam_id].origin.y -= movement.y;
		info->data.camera[info->data.option.cam_id].origin.z -= movement.z;
	}
	else if (key == KP_1)
		info->data.option.shadow = !info->data.option.shadow;
	else if (key == KP_2)
		info->data.option.anti_aliasing = !info->data.option.anti_aliasing;
	else if (key == KB_ESC || key == 17)
		exit(0);
	else if (key == KB_TAB)
	{
		if (info->data.option.cam_id == info->data.ca_nb - 1)
			info->data.option.cam_id = 0;
		else
			info->data.option.cam_id++;
	}
	screen_loop(&info->win, &info->data);
	return (1);
}
