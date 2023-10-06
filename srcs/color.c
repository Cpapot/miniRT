/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:02:22 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/13 15:42:56 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
#include "../inc/color.h"

int32_t	ft_color(int r, int g, int b, int T)
{
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (T << 24 | r << 16 | g << 8 | b << 0);
}

t_color	int_to_rgb(int32_t color)
{
	t_color	result;

	result.r = (color >> 16) & 0xFF;
	result.g = (color >> 8) & 0xFF;
	result.b = color & 0xFF;
	return (result);
}
