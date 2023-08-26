//
// Created by bpoumeau on 6/20/23.
//
#include "structure.h"
#include "libft.h"
#include "vec3.h"
#include "minirt_data.h"

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

t_disk	*copy_old_diskdata(t_minirt_data *data_pt)
{
	t_disk	*disk_arr;
	size_t	index;

	index = 0;
	disk_arr = malloc((data_pt->disk_nb + data_pt->cy_nb * 2 + data_pt->co_nb) * sizeof(t_disk));
	if (errno)
		return (perror("here"), free_minirt_data_content(data_pt), NULL);
	while (index != data_pt->disk_nb)
	{
		disk_arr[index] = data_pt->disk_arr[index];
		index++;
	}
	free(data_pt->disk_arr);
	return (disk_arr);
}

bool	add_disk(t_minirt_data *data_pt)
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
		disk_arr[data_pt->disk_nb + disk_index].color = data_pt->cylinder_arr[index].color;
		disk_arr[data_pt->disk_nb + disk_index].normal_vector = data_pt->cylinder_arr[index].normal_vector;
		disk_arr[data_pt->disk_nb + disk_index].diameter = data_pt->cylinder_arr[index].diameter;
		disk_arr[data_pt->disk_nb + disk_index].coordinate = data_pt->cylinder_arr[index].coordinate;
		disk_index++;
		disk_arr[data_pt->disk_nb + disk_index].color = data_pt->cylinder_arr[index].color;
		disk_arr[data_pt->disk_nb + disk_index].normal_vector = data_pt->cylinder_arr[index].normal_vector;
		disk_arr[data_pt->disk_nb + disk_index].diameter = data_pt->cylinder_arr[index].diameter;
		cyl_vec = data_pt->cylinder_arr[index].normal_vector;
		multiplying_vec(&cyl_vec, -(data_pt->cylinder_arr[index].height));
		disk_arr[data_pt->disk_nb + disk_index].coordinate.x = cyl_vec.x + disk_arr[data_pt->disk_nb + disk_index - 1].coordinate.x;
		disk_arr[data_pt->disk_nb + disk_index].coordinate.y = cyl_vec.y + disk_arr[data_pt->disk_nb + disk_index - 1].coordinate.y;
		disk_arr[data_pt->disk_nb + disk_index].coordinate.z = cyl_vec.z + disk_arr[data_pt->disk_nb + disk_index - 1].coordinate.z;
		disk_arr[data_pt->disk_nb + disk_index].normal_vector = data_pt->cylinder_arr[index].normal_vector;
		multiplying_vec(&disk_arr[data_pt->disk_nb + disk_index].normal_vector, -1);
		disk_index++;
		index++;
	}
	data_pt->disk_nb = data_pt->disk_nb + data_pt->cy_nb * 2;
	data_pt->disk_arr = disk_arr;
	return (true);
}

void	*suppress_light(t_light light, t_minirt_data *data_pt)
{
	size_t	lt_nb;

	lt_nb = data_pt->lt_nb;
	while (lt_nb--)
		if (ft_memcmp(&light, &(data_pt->lights_arr[lt_nb]), sizeof(t_light)) == 0)
		{
			data_pt->lt_nb--;
			return (ft_memmove((void *)&(data_pt->lights_arr[lt_nb]), (void *)&(data_pt->lights_arr[lt_nb + 1]),sizeof(t_light) * (data_pt->lt_nb - lt_nb)));
		}
	return (0);
}
