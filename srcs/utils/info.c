/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:16:23 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/07 13:17:39 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "window.h"
#define SUPR "\r\033[20K"

void	print_loading(int cam_id)
{
	static	int	percent = 0;
	int			total;
	static int	actual = 0;
	int	tmp ;

	total = XSIZE * YSIZE;
	actual++;
	tmp = (actual * 100) / total;
	if (tmp != percent)
	{
		percent = tmp;
		ft_printf(SUPR"cam %d [%d%%]", cam_id + 1, percent);
	}
	if (percent == 100)
	{
		percent = 0;
		actual = 0;
	}
}
