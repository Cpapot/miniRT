/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:05:06 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/21 12:29:41 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WINDOW_H
# define	WINDOW_H

//XSIZE > YSIZE
# define XSIZE		1280
# define YSIZE		720

typedef struct s_mlx_info
{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img_addrs;
	void	*img;
	int		xwinsize;
	int		ywinsize;
	int		bit_per_p;
	int		line_len;
	int		endian;
}	t_mlx_info;

void	ft_create_win(t_mlx_info *win);
void	my_mlx_pixel_put(t_mlx_info *win, int x, int y, int color);
void	init_mlx_info(t_mlx_info *info);

#endif
