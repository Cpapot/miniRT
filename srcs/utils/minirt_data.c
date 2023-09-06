//
// Created by bpoumeau on 6/13/23.
//

#include <stdlib.h>
#include "../../inc/structure.h"
#include <stdbool.h>
#include "errno.h"
#include <stdio.h>

bool	allocate_data(t_minirt_data *data_pt)
{
	errno = 0;
	data_pt->cylinder_arr = malloc(sizeof(t_cylinder) * data_pt->cy_nb);
	data_pt->sphere_arr = malloc(sizeof(t_sphere) * data_pt->sp_nb);
	data_pt->plane_arr = malloc(sizeof(t_plane) * data_pt->pl_nb);
	data_pt->lights_arr = malloc(sizeof(t_light) * data_pt->lt_nb);
	data_pt->ambient_light = malloc(sizeof(t_ambient_light) * data_pt->al_nb);
	data_pt->camera = malloc(sizeof (t_camera) * data_pt->ca_nb);
    data_pt->cone_arr = malloc(sizeof(t_cone) * data_pt->co_nb);
    data_pt->disk_arr = malloc(sizeof(t_disk) * data_pt->di_nb);
	if (errno)
		return (perror("allocate_data"), false);
	return (true);
}
