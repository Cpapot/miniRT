/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:25:47 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/20 15:49:00 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"

int	cut_infinite_object(t_point p, t_point coord, t_vec_3 norm, double h)
{
	t_vec_3	vec;

	vec = set_vec(coord.x - p.x, coord.y - p.y, coord.z - p.z);
	if (!(scalar_product(norm, vec) >= 0 && scalar_product(norm, vec) <= h))
		return (1);
	return (0);
}
