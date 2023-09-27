/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:46:28 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/27 02:37:18 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	ft_create_win(t_mlx_info *win)
{
	win->xwinsize = XSIZE;
	win->ywinsize = YSIZE;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->xwinsize, \
		win->ywinsize, "MiniRt");
}

void	my_mlx_pixel_put(t_mlx_info *win, int x, int y, int color)
{
	char	*dst;

	dst = win->img_addrs + (y * win->line_len + x * (win->bit_per_p / 8));
	*(unsigned int *)dst = color;
}
