/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:26:10 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/26 21:08:26 by cpapot           ###   ########.fr       */
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
		normalize_vec(&data_pt->cylinder_arr[index].normal);
		cyl_vec = data_pt->cylinder_arr[index].normal;
		multiplying_vec(&cyl_vec, data_pt->cylinder_arr[index].height / 2);
		data_pt->cylinder_arr[index].coord.x += cyl_vec.x;
		data_pt->cylinder_arr[index].coord.y += cyl_vec.y;
		data_pt->cylinder_arr[index].coord.z += cyl_vec.z;
		index++;
	}
}

t_disk	*copy_old_diskdata(t_data *data_pt)
{
	t_disk	*disk_arr;
	size_t	index;

	index = 0;
	disk_arr = malloc((data_pt->di_nb + data_pt->cy_nb * \
		4) * sizeof(t_disk));
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

t_point	change_disk_coord(t_vec_3 cyl_vec, t_point first_di, double height)
{
	t_point	result;

	multiplying_vec(&cyl_vec, -(height));
	result.x = cyl_vec.x + first_di.x;
	result.y = cyl_vec.y + first_di.y;
	result.z = cyl_vec.z + first_di.z;
	return (result);
}
/*
		disk_arr[pt->di_nb + i].color = pt->cylinder_arr[index].color;
		disk_arr[pt->di_nb + i].normal = pt->cylinder_arr[index].normal;
		disk_arr[pt->di_nb + i].diameter = pt->cylinder_arr[index].diameter;
		disk_arr[pt->di_nb + i].material = pt->cylinder_arr[index].material;
		disk_arr[pt->di_nb + i].normal = pt->cylinder_arr[index].normal;
		disk_arr[pt->di_nb + i].coord = change_disk_coord(pt->cylinder_arr[index].normal, disk_arr[pt->di_nb + i - 1].coord, pt->cylinder_arr[index].height);
		multiplying_vec(&disk_arr[pt->di_nb + i].normal, -1);
		i++;
		disk_arr[pt->di_nb + i].color = pt->cylinder_arr[index].color;
		disk_arr[pt->di_nb + i].normal = pt->cylinder_arr[index].normal;
		disk_arr[pt->di_nb + i].diameter = pt->cylinder_arr[index].diameter;
		disk_arr[pt->di_nb + i].coord = adjust_hitpoint(disk_arr[pt->di_nb + i - 1].coord , disk_arr[pt->di_nb + i].normal);
		disk_arr[pt->di_nb + i].material = pt->cylinder_arr[index].material;
		i++;
*/
void	set_disk(t_data *pt, int index)
{
	int	i;

	i = -1;
	while ((int)pt->cy_nb != index++)
	{
		while (i++ || true)
		{
			printf("i: %d et index: %d\n", i, index);
			pt->disk_arr[pt->di_nb + i].color = pt->cylinder_arr[index].color;
			pt->disk_arr[pt->di_nb + i].diameter = pt->cylinder_arr[index].diameter;
			pt->disk_arr[pt->di_nb + i].material = pt->cylinder_arr[index].material;
			pt->disk_arr[pt->di_nb + i].normal = pt->cylinder_arr[index].normal;
			if (i % 4 == 3)
				multiplying_vec(&pt->disk_arr[pt->di_nb + i].normal, -1);
			if (i % 4 == 1)
				pt->disk_arr[pt->di_nb + i].coord = adjust_hitpoint(pt->\
					cylinder_arr[index].coord , pt->disk_arr[pt->di_nb + i].normal);
			else if (i % 4 == 2)
				pt->disk_arr[pt->di_nb + i].coord = change_disk_coord(pt->\
					cylinder_arr[index].normal, pt->disk_arr[pt->di_nb + i - 1].\
					coord, pt->cylinder_arr[index].height);
			else
				pt->disk_arr[pt->di_nb + i].coord = pt->cylinder_arr[index].coord;
			if (i % 4 == 3)
			{
				printf("break\n");
				break;
			}
		}
	}
}

bool	add_disk(t_data *data_pt)
{
	t_disk	*disk_arr;
	int	index;

	index = -1;
	disk_arr = copy_old_diskdata(data_pt);
	if (!disk_arr)
		return (false);
	data_pt->disk_arr = disk_arr;
	set_disk(data_pt, index);
	data_pt->di_nb = data_pt->di_nb + data_pt->cy_nb * 4;
	data_pt->disk_arr = disk_arr;
	return (true);
}
