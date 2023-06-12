/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:46:28 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/12 13:54:27 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	ft_create_win(t_mlx_info *win)
{
	win->xwinsize = XSIZE;
	win->ywinsize = YSIZE;
	ft_printf("%d   %d", XSIZE, YSIZE);
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->xwinsize,
		win->ywinsize, "MiniRt");
	win->img = mlx_new_image(win->mlx_ptr, win->xwinsize, win->ywinsize);
	win->img_addrs = mlx_get_data_addr(win->img, &win->bit_per_p,
			&win->line_len, &win->endian);
}

void	my_mlx_pixel_put(t_mlx_info *win, int x, int y, int color)
{
	char	*dst;

	dst = win->img_addrs + (y * win->line_len + x * (win->bit_per_p / 8));
	*(unsigned int *)dst = color;
}


