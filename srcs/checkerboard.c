/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:35:31 by cpapot            #+#    #+#             */
/*   Updated: 2023/08/31 16:14:46 by cpapot           ###   ########.fr       */
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

t_vec_3	create_vec(t_point a, t_point b)
{
	t_vec_3 vec;

	vec.x = b.x - a.x;
	vec.y = b.y - a.y;
	vec.z = b.z - a.z;
	return (vec);
}
void	print_vector(t_vec_3 vector);

bool	same_dir(t_vec_3 a, t_vec_3 b)
{
	if (a.x * b.x > 0 && b.x != 0 && a.x != 0)
		return (true);
	if (a.z * b.z > 0 && b.z != 0 && a.z != 0)
		return (true);
	if (a.y * b.y > 0 && a.y != 0 && b.y != 0)
		return (true);
	return (false);
}

t_vec_3 vectoriel_product(t_vec_3 a, t_vec_3 b)
{
	t_vec_3 ret;

	ret.x = a.y * b.z - a.z * b.y;
	ret.y = a.z * b.x - a.x * b.z;
	ret.z = a.x * b.y - a.y * b.x;

	return (ret);
}

bool	is_black_case(t_point hitpoint)
{
	double	size;

	size = 10;
	if (sinf(size * hitpoint.x) * sinf(size * hitpoint.y) * sinf(size * hitpoint.z) < 0)
		return (false);
	return (true);
}


