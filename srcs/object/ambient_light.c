/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:52:51 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/17 19:26:17 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ambient_lightning(t_color *ratio, t_minirt_data *data)
{
	size_t				index;
	t_ambient_light		a_light;

	index = 0;
	while(data->al_nb != index)
	{
		a_light = data->ambient_light[index];
		a_light.ratio = 1;
		ratio->r += a_light.color.r * 0.00025 * a_light.ratio;
		ratio->g += a_light.color.g * 0.00025 * a_light.ratio;
		ratio->b += a_light.color.b * 0.00025 * a_light.ratio;
		index++;
	}
}
