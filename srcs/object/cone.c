/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:40:45 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/22 16:09:15 by cpapot           ###   ########.fr       */
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
	projected_vec.x = hitpoint.x;
	projected_vec.y = hitpoint.y;
	projected_vec.z = hitpoint.z;
	result.x = (hitpoint.x * scalar_product(projected_vec, cone.vector)) / scalar_product(projected_vec, projected_vec) - cone.vector.x;
	result.y = (hitpoint.y * scalar_product(projected_vec, cone.vector)) / scalar_product(projected_vec, projected_vec) - cone.vector.y;
	result.z = (hitpoint.z * scalar_product(projected_vec, cone.vector)) / scalar_product(projected_vec, projected_vec) - cone.vector.z;
	normalize_vec(&result);
	return (result);
}

double	cone_hitted(t_ray camray, t_cone cone)
{
	double	A;
	double	B;
	double	C;
	double	t;
	double	cosa;
	double	delta;
	t_point	hitpoint;
	t_vec_3	vec;

	cosa = acos((cone.diameter / 2) / sqrtf((cone.diameter / 2) * (cone.diameter / 2) + cone.height * cone.height));
	vec = set_vec(camray.origin.x - cone.coordinate.x, camray.origin.y - cone.coordinate.y, camray.origin.z - cone.coordinate.z);
	A = scalar_product(camray.direction, cone.vector) * scalar_product(camray.direction, cone.vector) - cosa * cosa;
	B = 2.0f * (scalar_product(camray.direction, cone.vector) * scalar_product(vec, cone.vector) - scalar_product(camray.direction, vec) * cosa * cosa);
	C = scalar_product(vec, cone.vector) * scalar_product(vec, cone.vector) - scalar_product(vec, vec) * cosa * cosa;
	delta = B * B - 4 * A * C;
	if (delta < 0)
		return (-1);
	delta = sqrtf(delta);
	t = (-B - delta) / (2.0f * A);
	if (t < 0 || (((-B + delta) / (2.0f * A)) > 0 && ((-B + delta) / (2.0f * A)) < t))
		t = (-B + delta) / (2.0f * A);
	if (t < 0)
		return (-1);
	hitpoint = hit_coord(t, camray);
	vec.x = hitpoint.x;
	vec.y = hitpoint.y;
	vec.z = hitpoint.z;
	if (scalar_product(vec, cone.vector) < 0 || scalar_product(vec, cone.vector) > cone.height)
		return (-1);
	return (t);
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

int32_t	render_cone(t_hitinfo info, t_ray camray, t_minirt_data data)
{
	t_cone		*co;
	t_color		ratio;

	co = (t_cone *)info.struct_info;
	ratio = ft_find_light_ratio(hit_coord(info.t, camray), data, \
	cone_normal(camray, info.t, *(t_cone *)info.struct_info));
	ambient_lightning(&ratio, &data);
	return (ft_color(co->color.r * ratio.r, co->color.g * \
	ratio.g, co->color.b * ratio.b, 0));
}
