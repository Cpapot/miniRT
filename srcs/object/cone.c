/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:40:45 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/21 17:28:33 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"

t_vec_3	cone_normal(t_ray camray, double t, t_cone cone)
{
	t_point	hitpoint;
	t_vec_3	projected_vec;
	t_vec_3	result;

	hitpoint = hit_coord(t, camray);
	projected_vec.x = hitpoint.x - cone.coordinate.x;
	projected_vec.y = 0;
	projected_vec.z = hitpoint.z - cone.coordinate.z;
	normalize_vec(&projected_vec);
	result.x = projected_vec.x * cone.height / (cone.diameter / 2);
	result.y = (cone.diameter / 2) / cone.height;
	result.z = projected_vec.z * cone.height / (cone.diameter / 2);
	return (result);
}

double	cone_hitted(t_ray camray, t_cone cone)
{
	double	A;
	double	B;
	double	C;
	double	cos;
	double	delta;
	t_vec_3	vec;

	cos = catan((cone.diameter/2)/ cone.height);
	vec.x = camray.origin.x - cone.coordinate.x;
	vec.y = camray.origin.y - cone.coordinate.y;
	vec.z = camray.origin.z - cone.coordinate.z;
	A = pow(scalar_product(camray.direction, cone.vector), 2) - cos;
	B = 2 * (scalar_product(camray.direction, cone.vector) * scalar_product(vec, cone.vector) - scalar_product(vec, camray.direction) * cos);
	C = scalar_product(vec, cone.vector) * scalar_product(vec, cone.vector) - scalar_product(vec, vec) * cos;
	delta = B * B - 4 * A * C;
	if (delta >= 0)
	{
		if (((-B + sqrt(delta)) / (2 * A)) > 0)
			return ((-B + sqrt(delta)) / (2 * A));
		else if (((-B - sqrt(delta)) / (2 * A)) > 0)
			return (-2);
		else
			return (-1);
	}
	return (-1);
}

int	find_near_cone(t_ray camray, size_t count, t_cone *cone_arr)
{
	size_t	index;
	double	tmp;
	double	t;
	int		id;

	id = -1;
	index = 0;
	tmp = INT_MAX;
	while (index != count)
	{
		t = cone_hitted(camray, cone_arr[index]);
		if (tmp > t && (t != -1 || t == -2))
		{
			tmp = t;
			id = index;
		}
		index++;
	}
	return (id);
}
