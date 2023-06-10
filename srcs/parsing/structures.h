/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:32:29 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/06/10 17:27:48 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_minirt_data	t_minirt_data;
typedef struct s_point			t_point;
typedef struct s_vec_3			t_vec_3;
typedef struct s_color			t_color;
typedef struct s_ambient_light	t_ambient_light;
typedef struct s_camera			t_camera;
typedef struct s_light			t_light;
typedef struct s_sphere			t_sphere;
typedef struct s_plane			t_plane;
typedef struct s_cylinder		t_cylinder;
typedef struct s_ray			t_ray;


struct s_minirt_data
{
	t_ambient_light	*ambient_light;
	t_camera		*camera;
	t_light			*lights_arr;
	t_sphere		*sphere_arr;
	t_plane			*plane_arr;
	t_cylinder		*cylinder_arr;
};

struct	s_point
{
	double	x;
	double	y;
	double	z;
};

struct	s_ray
{
	t_vec_3	direction;
	t_point	origin;
};

struct	s_vec_3
{
	double	x;
	double	y;
	double	z;
	double	norme;
};

struct	s_color
{
	char	r;
	char	g;
	char	b;
};

struct	s_ambient_light
{
	t_color color;
	float	ratio;
};

struct	s_camera
{
	t_vec_3	vector;
	t_point	origin;
	float	fov;
};

struct	s_light
{
	t_point	coordinate;
	t_vec_3	vector;
	float	brightness;
};

struct	s_sphere
{
	t_point	origin;
	double	diameter;
	t_color	color;
};

struct	s_plane
{
	t_point	coordinate;
	t_vec_3	normal_vector;
	t_color	colors;
};

struct	s_cylinder
{
	t_point	coordinate;
	t_vec_3	normal_vector;
	double	diameter;
	double	height;
	t_color	colors;
};

#endif
