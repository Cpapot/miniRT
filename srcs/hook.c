/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:00:33 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/19 13:56:44 by cpapot           ###   ########.fr       */
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
		movement = set_vec(0, 0.07, 0);
		info->data.camera[0].vector = adding_vec(info->data.camera[0].vector, movement);
		normalize_vec(&info->data.camera[0].vector);
	}
	else if (key == KB_DOWN)
	{
		movement = set_vec(0, -0.07, 0);
		info->data.camera[0].vector = adding_vec(info->data.camera[0].vector, movement);
		normalize_vec(&info->data.camera[0].vector);
	}
	else if (key == KB_LEFT)
	{
		movement = set_vec(-0.07, 0, 0);
		info->data.camera[0].vector = adding_vec(info->data.camera[0].vector, movement);
		normalize_vec(&info->data.camera[0].vector);
	}
	else if (key == KB_RIGHT)
	{
		movement = set_vec(0.07, 0, 0);
		info->data.camera[0].vector = adding_vec(info->data.camera[0].vector, movement);
		normalize_vec(&info->data.camera[0].vector);
	}
	else if (key == KB_W)
	{
		movement = info->data.camera[0].vector;
		info->data.camera[0].origin.x += movement.x * 0.1;
		info->data.camera[0].origin.y += movement.y * 0.1;
		info->data.camera[0].origin.z += movement.z * 0.1;
	}
	else if (key == KB_S)
	{
		movement = info->data.camera[0].vector;
		info->data.camera[0].origin.x -= movement.x * 0.1;
		info->data.camera[0].origin.y -= movement.y * 0.1;
		info->data.camera[0].origin.z -= movement.z * 0.1;
	}
	else if (key == KB_ESC || key == 17)
		exit(0);
	screen_loop(&info->win, &info->data);
	return (1);
}
