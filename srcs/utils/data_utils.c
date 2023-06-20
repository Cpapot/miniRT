//
// Created by bpoumeau on 6/20/23.
//
#include "structure.h"
#include "libft.h"

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