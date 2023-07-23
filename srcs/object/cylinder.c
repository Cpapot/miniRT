/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:54:31 by cpapot            #+#    #+#             */
/*   Updated: 2023/07/23 16:26:23 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "vec3.h"

t_vec_3 cylinder_normal(t_ray camray)
{
	t_vec_3	result;

	result = set_vec(camray.origin.x, 0,camray.origin.z);
	normalize_vec(&result);
	return (result);
}

double	cylinder_hitted(t_ray camray, t_cylinder cyl)
{
	double	A;
	double	B;
	double	C;
	double	delta;
	double	t;

	A = cyl.normal_vector.x * cyl.normal_vector.x + cyl.normal_vector.z * cyl.normal_vector.z;
	B = 2 * (cyl.normal_vector.x * camray.origin.x + cyl.normal_vector.z * camray.origin.z);
	C = pow((camray.direction.x - cyl.coordinate.x), 2) + pow((camray.direction.z - cyl.coordinate.z), 2) - (pow(cyl.diameter / 2, 2));
	delta = B * B - 4 * A * C;
	if (delta < 0)
		return (-1);
	delta = sqrtf(delta);
	t = ((-B - delta)/(2*A));
	if (t > (-B + delta)/(2*A) && (-B + delta)/(2*A) > 0)
		t = (-B + delta)/(2*A);
	return (t);
}

int		find_near_cylinder(t_ray camray, size_t count, t_cylinder *cyl_arr)
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
		t = cylinder_hitted(camray, cyl_arr[index]);
		if (tmp > t && (t != -1 || t == -2))
		{
			tmp = t;
			id = index;
		}
		index++;
	}
	return (id);
}

int32_t	render_cylinder(t_hitinfo info, t_ray camray, t_minirt_data data)
{
	t_cylinder	*cy;
	t_color		ratio;

	cy = (t_cylinder *)info.struct_info;
	ratio = ft_find_light_ratio(hit_coord(info.t, camray), data, \
	cylinder_normal(camray));
	ambient_lightning(&ratio, &data);
	return (ft_color(cy->color.r * ratio.r, cy->color.g * \
	ratio.g, cy->color.b * ratio.b, 0));
}
