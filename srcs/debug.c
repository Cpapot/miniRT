//
// Created by bpoumeau on 6/14/23.
//

#include "structure.h"

#include "stdio.h"

void	print_vector(t_vec_3 vector)
{
	printf("vector\nx %f y %f z %f\n", vector.x, vector.y, vector.z);
}

void	print_point(t_point point)
{
	printf("coordinante\nx %f, y %f, z %f\n", point.x, point.y, point.z);
}

void print_data(char *msg, t_minirt_data *data)
{
	static	int nb = 0;

	printf("debug print data %d\n", nb);
	if (msg)
		printf("msg : %s\n", msg);
	size_t	size;

	size = data->ca_nb;
	t_camera	*tmp_ca;
	tmp_ca = data->camera;
	while (size--)
	{
		printf("camera : %f\n", tmp_ca->fov);
		print_vector(tmp_ca->vector);
		print_point(tmp_ca->origin);
		tmp_ca++;
	}
	//t_sphere 	*sp_ca;
	//sp_ca = data->sphere_arr;
	//size = data->sphere_arr;
}


