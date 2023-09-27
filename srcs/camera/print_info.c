/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:29:07 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/27 15:50:25 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "window.h"
#define SUPR "\r\033[20K"

void	print_loading(int cam)
{
	static int	percent = 0;
	int			total;
	static int	actual = 0;
	int			tmp ;

	total = XSIZE * YSIZE;
	tmp = (actual++ *100) / total;
	if (percent == 100)
	{
		percent = 0;
		actual = 0;
		ft_printf(SUPR"LOADING SCENE (CAM: %d)... [%d%%]  ", cam, 100);
	}
	else if (tmp != percent)
	{
		percent = tmp;
		if (percent != 100)
			ft_printf(SUPR"LOADING SCENE (CAM: %d)... [%d%%]  ", cam, percent);
	}
}

void	print_info(t_data *data)
{
	ft_printf("\e[2J\e[H");
	if (data->option.shadow)
		ft_printf(" ✅ | shadows\n");
	else
		ft_printf(" ❌ | shadows\n");
	if (data->option.anti_aliasing)
		ft_printf(" ✅ | anti aliasing\n");
	else
		ft_printf(" ❌ | anti aliasing\n");
	ft_printf("%d/%d | cam ID\n", data->option.cam_id + 1, data->ca_nb);
}
