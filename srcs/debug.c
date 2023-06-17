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

void	print_color(t_color color)
{
	printf("color %f %f %f.\n", color.r, color.g, color.b);
}

void	print_ray(t_ray ray)
{
	printf("\n\nray\n");
	print_vector(ray.direction);
	print_point(ray.origin);
}

void	print_camera(t_camera camera)
{
	printf("\n\ncamera\n");
	print_point(camera.origin);
	print_vector(camera.vector);
	printf("fov : %f\n", camera.fov);
}

void	print_ambient_light(t_ambient_light al)
{
	printf("\n\nambient light\n");
	print_color(al.color);
	printf("ration %f\n", al.ratio);
}

void	print_light(t_light light)
{
	printf("\n\nlight\n");
	print_point(light.coordinate);
	print_color(light.color);
	printf("brightness %f\n", light.brightness);
}

void	print_sphere(t_sphere sphere)
{
	printf("\n\nsphere\n");
	print_point(sphere.origin);
	printf("diameter %f\n", sphere.diameter);
	print_color(sphere.color);
}

void	print_plane(t_plane plane)
{
	printf("\n\nplane\n");
	print_point(plane.coordinate);
	print_vector(plane.normal_vector);
	print_color(plane.color);
}

void	print_cylinder(t_cylinder cylinder)
{
	printf("\n\ncylinder\n");
	print_point(cylinder.coordinate);
	print_vector(cylinder.normal_vector);
	printf("diameter %f, height %f\n", cylinder.diameter, cylinder.height);
	print_color(cylinder.color);
}

void print_data(char *msg, t_minirt_data *data)
{
	static	int nb = 0;

	printf("debug print data %d\n", nb);
	if (msg)
		printf("msg : %s\n", msg);
	size_t	size;

	size = data->sp_nb;
	t_sphere	*tmp_sp;
	tmp_sp = data->sphere_arr;
	while (size--)
	{
		print_sphere(*tmp_sp);
		tmp_sp++;
	}
	size = data->ca_nb;
	t_camera 	*tmp_ca;
	tmp_ca = data->camera;
	while (size--)
	{
		print_camera(*tmp_ca);
		tmp_ca++;
	}
	size = data->cy_nb;
	t_cylinder 	*tmp_cy;
	tmp_cy = data->cylinder_arr;
	while (size--)
	{
		print_cylinder(*tmp_cy);
		tmp_cy++;
	}
	size = data->pl_nb;
	t_plane	*tmp_pl;
	tmp_pl = data->plane_arr;
	while (size--)
	{
		print_plane(*tmp_pl);
		tmp_pl++;
	}
	size = data->al_nb;
	t_ambient_light 	*tmp_al;
	tmp_al = data->ambient_light;
	while (size--)
	{
		print_ambient_light(*tmp_al);
		tmp_al++;
	}
	size = data->lt_nb;
	t_light 	*tmp_lt;
	tmp_lt = data->lights_arr;
	while (size--)
	{
		print_light(*tmp_lt);
		tmp_lt++;
	}
}
