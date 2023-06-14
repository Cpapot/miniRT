//
// Created by bpoumeau on 6/13/23.
//

#include <stdlib.h>
#include "structure.h"
#include <stdbool.h>
#include "errno.h"
#include <stdio.h>

void	free_minirt_data_content(t_minirt_data *data_pt)
{
	free(data_pt->cylinder_arr);
	free(data_pt->sphere_arr);
	free(data_pt->plane_arr);
	free(data_pt->lights_arr);
	free(data_pt->ambient_light);
	free(data_pt->camera);
}

void	print_data(char *msg, t_minirt_data *data)
{
	puts(msg);
	printf("A %ld : %p\n", data->al_nb, data->ambient_light);
	printf("c %ld : %p\n", data->ca_nb, data->camera);
	printf("l %ld : %p\n", data->lt_nb, data->lights_arr);
	printf("s %ld : %p\n", data->sp_nb, data->sphere_arr);
	printf("p %ld : %p\n", data->pl_nb, data->plane_arr);
	printf("n %ld : %p\n", data->cy_nb, data->cylinder_arr);
}

bool	allocate_data(t_minirt_data *data_pt)
{
	errno = 0;
	data_pt->cylinder_arr = malloc(sizeof(t_cylinder) * data_pt->cy_nb);
	data_pt->sphere_arr = malloc(sizeof(t_sphere) * data_pt->sp_nb);
	data_pt->plane_arr = malloc(sizeof(t_plane) * data_pt->pl_nb);
	data_pt->lights_arr = malloc(sizeof(t_light) * data_pt->lt_nb);
	data_pt->ambient_light = malloc(sizeof(t_ambient_light) * data_pt->al_nb);
	data_pt->camera = malloc(sizeof (t_camera) * data_pt->ca_nb);
	print_data("allocate data", data_pt);
	puts("allocated");
	if (errno)
		return (perror("here"), free_minirt_data_content(data_pt), false);
	puts("damned");
	return (true);
}
