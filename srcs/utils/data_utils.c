/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:26:10 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 17:12:17 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "minirt_data.h"

t_point	adjust_hitpoint(t_point hit, t_vec_3 normal);

void	change_cylinder_coord(t_data *data_pt)
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

t_disk	*copy_old_diskdata(t_data *data_pt)
{
	t_disk	*disk_arr;
	size_t	index;

	index = 0;
	disk_arr = malloc((data_pt->di_nb + data_pt->cy_nb * \
		4 + data_pt->co_nb) * sizeof(t_disk));
	if (errno)
		return (perror("here"), clean_minirt_data(data_pt), NULL);
	while (index != data_pt->di_nb)
	{
		disk_arr[index] = data_pt->disk_arr[index];
		index++;
	}
	free(data_pt->disk_arr);
	return (disk_arr);
}

void	add_cone_disk(
		t_disk **disk_arr,
		t_data *data_pt,
		size_t disk_index)
{
	t_cone	cone;
	size_t	index;
	t_vec_3	normal;

	index = 0;
	while (data_pt->co_nb != index)
	{
		cone = data_pt->cone_arr[index];
		disk_arr[data_pt->di_nb + disk_index]->color = cone.color;
		normalize_vec(&data_pt->cone_arr[index].vector);
		normal = data_pt->cone_arr[index].vector;
		multiplying_vec(&normal, -(cone.height));
		disk_arr[data_pt->di_nb + disk_index]->coordinate.x = normal.x + \
			cone.coordinate.x;
		disk_arr[data_pt->di_nb + disk_index]->coordinate.y = normal.y + \
			cone.coordinate.y;
		disk_arr[data_pt->di_nb + disk_index]->coordinate.z = normal.z + \
			cone.coordinate.z;
		disk_arr[data_pt->di_nb + disk_index]->material = cone.material;
		disk_arr[data_pt->di_nb + disk_index]->diameter = cone.diameter;
		disk_arr[data_pt->di_nb + disk_index]->normal_vector = cone.vector;
		disk_index++;
		index++;
	}
}

bool	add_disk(t_data *data_pt)
{
	size_t	index;
	size_t	disk_index;
	t_disk	*disk_arr;
	t_vec_3	cyl_vec;

	index = 0;
	disk_index = 0;
	disk_arr = copy_old_diskdata(data_pt);
	if (!disk_arr)
		return (false);
	while (data_pt->cy_nb != index)
	{
		disk_arr[data_pt->di_nb + disk_index].color = data_pt->cylinder_arr[index].color;
		disk_arr[data_pt->di_nb + disk_index].normal_vector = data_pt->cylinder_arr[index].normal_vector;
		disk_arr[data_pt->di_nb + disk_index].diameter = data_pt->cylinder_arr[index].diameter;
		disk_arr[data_pt->di_nb + disk_index].coordinate = data_pt->cylinder_arr[index].coordinate;
		disk_arr[data_pt->di_nb + disk_index].material = data_pt->cylinder_arr[index].material;
		disk_index++;
		disk_arr[data_pt->di_nb + disk_index].color = data_pt->cylinder_arr[index].color;
		disk_arr[data_pt->di_nb + disk_index].normal_vector = data_pt->cylinder_arr[index].normal_vector;
		multiplying_vec(&disk_arr[data_pt->di_nb + disk_index].normal_vector, -1);
		disk_arr[data_pt->di_nb + disk_index].diameter = data_pt->cylinder_arr[index].diameter;
		disk_arr[data_pt->di_nb + disk_index].coordinate = adjust_hitpoint(data_pt->cylinder_arr[index].coordinate , disk_arr[data_pt->di_nb + disk_index].normal_vector);
		disk_arr[data_pt->di_nb + disk_index].material = data_pt->cylinder_arr[index].material;
		disk_index++;
		disk_arr[data_pt->di_nb + disk_index].color = data_pt->cylinder_arr[index].color;
		disk_arr[data_pt->di_nb + disk_index].normal_vector = data_pt->cylinder_arr[index].normal_vector;
		disk_arr[data_pt->di_nb + disk_index].diameter = data_pt->cylinder_arr[index].diameter;
		disk_arr[data_pt->di_nb + disk_index].material = data_pt->cylinder_arr[index].material;
		cyl_vec = data_pt->cylinder_arr[index].normal_vector;
		multiplying_vec(&cyl_vec, -(data_pt->cylinder_arr[index].height));
		disk_arr[data_pt->di_nb + disk_index].coordinate.x = cyl_vec.x + disk_arr[data_pt->di_nb + disk_index - 1].coordinate.x;
		disk_arr[data_pt->di_nb + disk_index].coordinate.y = cyl_vec.y + disk_arr[data_pt->di_nb + disk_index - 1].coordinate.y;
		disk_arr[data_pt->di_nb + disk_index].coordinate.z = cyl_vec.z + disk_arr[data_pt->di_nb + disk_index - 1].coordinate.z;
		disk_arr[data_pt->di_nb + disk_index].normal_vector = data_pt->cylinder_arr[index].normal_vector;
		multiplying_vec(&disk_arr[data_pt->di_nb + disk_index].normal_vector, -1);
		disk_index++;
		disk_arr[data_pt->di_nb + disk_index].color = data_pt->cylinder_arr[index].color;
		disk_arr[data_pt->di_nb + disk_index].normal_vector = data_pt->cylinder_arr[index].normal_vector;
		disk_arr[data_pt->di_nb + disk_index].diameter = data_pt->cylinder_arr[index].diameter;
		disk_arr[data_pt->di_nb + disk_index].coordinate = adjust_hitpoint(disk_arr[data_pt->di_nb + disk_index - 1].coordinate , disk_arr[data_pt->di_nb + disk_index].normal_vector);
		disk_arr[data_pt->di_nb + disk_index].material = data_pt->cylinder_arr[index].material;
		disk_index++;
		index++;
	}
	index = 0;
	while (data_pt->co_nb != index)
	{
		disk_arr[data_pt->di_nb + disk_index].color = data_pt->cone_arr[index].color;
		normalize_vec(&data_pt->cone_arr[index].vector);
		cyl_vec = data_pt->cone_arr[index].vector;
		multiplying_vec(&cyl_vec, -(data_pt->cone_arr[index].height));
		disk_arr[data_pt->di_nb + disk_index].coordinate.x = cyl_vec.x + data_pt->cone_arr[index].coordinate.x;
		disk_arr[data_pt->di_nb + disk_index].coordinate.y = cyl_vec.y + data_pt->cone_arr[index].coordinate.y;
		disk_arr[data_pt->di_nb + disk_index].coordinate.z = cyl_vec.z + data_pt->cone_arr[index].coordinate.z;
		disk_arr[data_pt->di_nb + disk_index].material = data_pt->cone_arr[index].material;
		disk_arr[data_pt->di_nb + disk_index].diameter = data_pt->cone_arr[index].diameter;
		disk_arr[data_pt->di_nb + disk_index].normal_vector = data_pt->cone_arr[index].vector;
		disk_index++;
		index++;
	}
	data_pt->di_nb = data_pt->di_nb + data_pt->cy_nb * 4 + data_pt->co_nb;
	data_pt->disk_arr = disk_arr;
	return (true);
}
