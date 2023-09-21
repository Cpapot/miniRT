/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:59:53 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/21 15:39:57 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_hit	set_hit(bool inside, double t);

t_hit	quadratic_equation_inside(double a, double b, double c)
{
	double	delta;
	double	t1;
	double	t2;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (set_hit(0, -1));
	delta = sqrtf(delta);
	if (delta >= 0)
	{
		t1 = (-b - delta) / (2.0f * a);
		t2 = (-b + delta) / (2.0f * a);
		if (t1 > 0)
			return (set_hit(0, t1));
		else if (t1 < 0 && t2 > 0)
			return (set_hit(1, t2));
		else
			return (set_hit(0, -1));
	}
	return (set_hit(0, -1));
}

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
			return (-2);
		else
			return (-1);
	}
	return (-1);
}
