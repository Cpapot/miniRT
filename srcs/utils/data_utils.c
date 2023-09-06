//
// Created by bpoumeau on 6/20/23.
//
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

t_disk	*copy_old_diskdata(t_minirt_data *data_pt)
{
	t_disk	*disk_arr;
	size_t	index;

	index = 0;
	disk_arr = malloc((data_pt->di_nb + data_pt->cy_nb * 2 + data_pt->co_nb) * sizeof(t_disk));
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
