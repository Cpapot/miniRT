//
// Created by bpoumeau on 6/9/23.
//

#ifndef STRUCTURES_H

# define STRUCTURES_H

typedef struct s_minirt_data
{
	t_ambient_light	*ambient_light;
	t_camera		*camera;
	t_light			*lights_arr;
	t_sphere		*sphere_arr;
	t_plane			*plane_arr;
	t_cylinder		*cylinder_arr;
}	t_minirt_data;

typedef	struct	s_point
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

typedef struct	s_color
{
	char	r;
	char	g;
	char	b;
}	t_color;

typedef struct	s_ambient_light
{
	t_color color;
	float	ratio;
}	t_ambient_light;

typedef struct	s_camera
{
	t_vec_3			vector;
	t_point			coordinate;
	char 			fov;
}	t_camera;

typedef struct	s_light
{
	t_point			coordinate;
	t_vec_3			vector;
	float			brightness;
}	t_light;

typedef struct	s_sphere
{
	t_point	origin;
	double	diameter;
	t_color	color;
}	t_sphere;

typedef struct	s_plane
{
	t_point	coordinate;
	t_vec_3	normal_vector;
	t_color	colors;
}	t_plane;

typedef struct	s_cylinder
{
	t_point	coordinate;
	t_vec_3	normal_vector;
	double	diameter;
	double	height;
	t_color	colors;
}	t_cylinder;

#endif
