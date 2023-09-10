/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:29:07 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/10 15:03:23 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "window.h"
#define SUPR "\r\033[20K"

void	print_loading(void)
{
	static	int	percent = 0;
	int			total;
	static int	actual = 0;
	int			tmp ;

	total = XSIZE * YSIZE;
	actual++;
	tmp = (actual * 100) / total;
	if (tmp != percent)
	{
		percent = tmp;
		ft_printf(SUPR"LOADING SCENE... [%d%%]", percent);
	}
	if (percent == 100)
	{
		percent = 0;
		actual = 0;
		ft_printf("\e[2J\e[H");
		ft_printf(GREEN"SCENE LOADED  \n"WHITE);
	}
}

void	print_info(t_minirt_data *data)
{
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
