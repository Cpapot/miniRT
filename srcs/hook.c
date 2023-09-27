/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:00:33 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/27 02:33:34 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "../inc/key.h"
#include "close.h"

t_img_info	*render_all_img(t_mlx_info *win, t_data *data);
void		screen_loop(t_mlx_info *win, t_data *data);

int	close_window(void)
{
	exit(EXIT_SUCCESS);
}

int	deal_key(int key, t_general *info)
{
	if (key == KP_1)
		info->data->option.shadow = !info->data->option.shadow;
	else if (key == KP_2)
	{
		info->data->option.anti_aliasing = !info->data->option.anti_aliasing;
		destroy_image_arr(info->win, info->data);
		info->win->img_arr = render_all_img(info->win, info->data);
	}
	else if (key == KB_ESC || key == 17)
		close_minirt(info->win, info->data, 0);
	else if (key == KB_TAB)
	{
		if (info->data->option.cam_id == info->data->ca_nb - 1)
			info->data->option.cam_id = 0;
		else
			info->data->option.cam_id++;
	}
	screen_loop(info->win, info->data);
	return (1);
}
