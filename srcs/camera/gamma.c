/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamma.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:27:37 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 14:31:11 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "color.h"

int32_t	mod_gamma(int32_t object_color)
{
	t_color	gamma;
	t_color	color;
	double	scale;

	scale = 155;
	color = int_to_rgb(object_color);
	gamma.r = sqrt(scale * color.r);
	gamma.g = sqrt(scale * color.g);
	gamma.b = sqrt(scale * color.b);
	return (ft_color(gamma.r, gamma.g, gamma.b, 0));
}
