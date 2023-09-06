/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:59:53 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/06 22:16:33 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/structure.h"
#include "../../libft/includes/libft.h"
#include "../../inc/vec3.h"
#include "../../inc/minirt_data.h"

void	change_cylinder_coord(t_minirt_data *data_pt)
{
	size_t	index;
	t_vec_3	cyl_vec;

	index = 0;
	while (data_pt->cy_nb != index)
	{
		normalize_vec(&data_pt->cylinder_arr[index].normal_vector);
		cyl_vec = data_pt->cylinder_arr[index].normal_vector;
		multiplying_vec(&cyl_vec, data_pt->cylinder_arr[index].height / 2);
		data_pt->cylinder_arr[index].coordinate.x += cyl_vec.x;
		data_pt->cylinder_arr[index].coordinate.y += cyl_vec.y;
		data_pt->cylinder_arr[index].coordinate.z += cyl_vec.z;
		index++;
	}
}

void	*suppress_light(t_light light, t_minirt_data *data_pt)
{
	size_t	lt_nb;
	void	*ret_val;

	lt_nb = data_pt->lt_nb;
	while (lt_nb--)
	{
		if (ft_memcmp(&light, \
		&(data_pt->lights_arr[lt_nb]), sizeof(t_light)) == 0)
		{
			data_pt->lt_nb--;
			ret_val = ft_memmove((void *) &(data_pt->lights_arr[lt_nb]), \
							(void *) &(data_pt->lights_arr[lt_nb + 1]), \
							sizeof(t_light) * (data_pt->lt_nb - lt_nb));
			return (ret_val);
		}
	}
	return (NULL);
}
