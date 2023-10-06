/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:37:21 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/21 13:55:39 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "camera.h"
#include "color.h"

t_color	get_average_color(t_color color_arr[4])
{
	t_color	result;
	int		index;

	result.r = 0;
	result.g = 0;
	result.b = 0;
	index = 0;
	while (index != 4)
	{
		result.r += color_arr[index].r;
		result.g += color_arr[index].g;
		result.b += color_arr[index].b;
		index++;
	}
	result.r /= 4;
	result.g /= 4;
	result.b /= 4;
	return (result);
}

int32_t	anti_aliasing(t_data *data, int x, int y, t_camera cam)
{
	int			index;
	t_ray		camray;
	t_color		color_arr[4];
	t_color		result;

	index = 0;
	while (index != 4)
	{
		camray = find_aliasing_ray(cam, x, y, index);
		color_arr[index] = int_to_rgb(check_ray(camray, *data, 1));
		index++;
	}
	result = get_average_color(color_arr);
	return (ft_color(result.r, result.g, result.b, 0));
}
