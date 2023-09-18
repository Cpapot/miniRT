/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:59:53 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/28 20:17:02 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

double	quadratic_equation(double a, double b, double c)
{
	double	delta;
	double	t1;
	double	t2;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	delta = sqrtf(delta);
	if (delta >= 0)
	{
		t1 = (-b - delta) / (2.0f * a);
		t2 = (-b + delta) / (2.0f * a);
		if (t1 > 0)
			return (t1);
		else if (t2 > 0)
			return (t2);
		else
			return (-1);
	}
	return (-1);
}
