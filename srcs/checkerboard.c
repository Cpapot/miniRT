/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:31 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/30 21:38:00 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	sphere_mapping(t_point point, double radius)
{
	t_point	result;

	result.z = 0;
	result.x = point.x / radius;
	result.y = 2 * atan(exp(point.y / radius)) - M_PI / 2;
	return (result);
}

bool	is_black_case_sp(t_point hitpoint)
{
	double	size;

	size = 20;
	if (sinf(size * hitpoint.x) * sinf(size * hitpoint.y) < 0)
		return (true);
	return (false);
}

//remplacer false par true
bool	is_black_case(t_point hitpoint)
{
	double	size;

	size = 10;
	if (sinf(size * hitpoint.x) * sinf(size * hitpoint.y) * sinf(size * hitpoint.z) < 0)
		return (false);
	return (false);
}

