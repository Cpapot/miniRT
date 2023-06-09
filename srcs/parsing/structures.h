//
// Created by bpoumeau on 6/9/23.
//

#ifndef STRUCTURES_H

# define STRUCTURES_H

#include "sphere_parsing.h"
#include "camera_parsing.h"
#include "light_parsing.h"
#include "sphere_parsing.h"
#include "plane_parsing.h"

typedef struct s_minirt_data
{
	t_ambient_light	*ambient_light;
	t_camera		*camera;
	t_light			*lights_arr;
	t_sphere		*sphere_arr;
	t_plane			*plane_arr;
	t_cylinder		*cylinder_arr;
}	t_minirt_data;

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct	s_vec_3
{
	double	x;
	double	y;
	double	z;
	double	norme;
}	t_vec_3;

typedef struct	s_ambient_light
{
	float	ratio;
	char 	r;
	char 	g;
	char 	b;
}	t_ambient_light;

typedef struct	s_camera
{
	t_vec_3			vector;
	t_point			coordinate;
	char 			fov;
}	t_camera;

typedef struct	s_light
{
	t_coordinate	coordinate;
	t_vec_3			vector;
	float			brightness;
}	t_light;

typedef struct	t_sphere
{

};

#endif
