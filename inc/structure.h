/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:19:45 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/26 20:25:22 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/**** --size_t-- ****/
# include <stdbool.h>

/**** --bool-- ****/
# include <stdlib.h>

enum	e_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	DISK
};

typedef struct s_minirt_data	t_data;
typedef struct s_ray			t_ray;
typedef struct s_point			t_point;
typedef struct s_vec_3			t_vec_3;
typedef struct s_color			t_color;
typedef struct s_camera			t_camera;
typedef struct s_ambient_light	t_ambient_light;
typedef struct s_light			t_light;
typedef struct s_sphere			t_sphere;
typedef struct s_plane			t_plane;
typedef struct s_cylinder		t_cylinder;
typedef struct s_cone			t_cone;
typedef struct s_disk			t_disk;
typedef struct s_option			t_option;
typedef struct s_material		t_material;

struct s_material
{
	double	reflection;
	double	specular_coef;
	double	alpha;
	bool	is_board;
};

struct s_option
{
	int		shadow;
	int		anti_aliasing;
	size_t	tmp;
	size_t	cam_id;
};

struct s_minirt_data
{
	size_t			al_nb;
	t_ambient_light	*ambient_light;
	size_t			ca_nb;
	t_camera		*camera;
	size_t			lt_nb;
	t_light			*lights_arr;
	size_t			sp_nb;
	t_sphere		*sphere_arr;
	size_t			pl_nb;
	t_plane			*plane_arr;
	size_t			cy_nb;
	t_cylinder		*cylinder_arr;
	size_t			co_nb;
	t_cone			*cone_arr;
	size_t			di_nb;
	t_disk			*disk_arr;
	t_option		option;
	int				level;
};

struct	s_point
{
	double	x;
	double	y;
	double	z;
};

struct	s_vec_3
{
	double	x;
	double	y;
	double	z;
	double	norme;
};

struct	s_ray
{
	t_vec_3	direction;
	t_point	origin;
};

struct	s_color
{
	double	r;
	double	g;
	double	b;
};

struct	s_camera
{
	t_vec_3		vector;
	t_point		origin;
	double		fov;
};

struct	s_ambient_light
{
	t_color	color;
	double	ratio;
};

struct	s_light
{
	t_point	coordinate;
	double	brightness;
	t_color	color;
};

struct	s_sphere
{
	t_point		origin;
	double		diameter;
	t_color		color;
	t_material	material;
};

struct	s_plane
{
	t_point		coordinate;
	t_vec_3		normal_vector;
	t_color		color;
	t_material	material;
};

struct	s_disk
{
	t_point		coord;
	t_vec_3		normal;
	double		diameter;
	t_color		color;
	t_material	material;
};

struct	s_cone
{
	t_point		coordinate;
	t_vec_3		vector;
	double		diameter;
	double		height;
	t_color		color;
	t_material	material;
};

struct	s_cylinder
{
	t_point		coord;
	t_vec_3		normal;
	double		diameter;
	double		height;
	t_color		color;
	t_material	material;
};

typedef struct s_hit
{
	double	t;
	int		id;
	bool	inside;
}	t_hit;

typedef struct s_hitinfo
{
	double	t;
	int		type;
	void	*struct_info;
	bool	inside;
	t_vec_3	normal;
}			t_hitinfo;

#endif
