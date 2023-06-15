#include "../inc/miniRT.h"

t_light		init_light()
{
	t_light	light;

	light.coordinate.x = 0;
	light.coordinate.y = 10;
	light.coordinate.z = 0;
	return (light);
}

t_sphere	init_sphere()
{
	t_sphere	sphere;

	sphere.diameter = 2;
	sphere.origin.x = 0;
	sphere.origin.y = 0;
	sphere.origin.z = 0;
	sphere.color.r = 255;
	sphere.color.g = 0;
	sphere.color.b = 0;
	return (sphere);
}

t_sphere	init_sphere2()
{
	t_sphere	sphere;

	sphere.diameter = 3;
	sphere.origin.x = 3;
	sphere.origin.y = 0;
	sphere.origin.z = 0;
	sphere.color.r = 50;
	sphere.color.g = 0;
	sphere.color.b = 20;
	return (sphere);
}

t_sphere	init_sphere3()
{
	t_sphere	sphere;

	sphere.diameter = 6;
	sphere.origin.x = 6;
	sphere.origin.y = 0;
	sphere.origin.z = 0;
	sphere.color.r = 43;
	sphere.color.g = 177;
	sphere.color.b = 34;
	return (sphere);
}

t_sphere	init_sphere4()
{
	t_sphere	sphere;

	sphere.diameter = 6;
	sphere.origin.x = 6;
	sphere.origin.y = -10;
	sphere.origin.z = 7;
	sphere.color.r = 255;
	sphere.color.g = 0;
	sphere.color.b = 0;
	return (sphere);
}

t_plane		init_plane()
{
	t_plane	plane;

	plane.coordinate.x = 0;
	plane.coordinate.y = -5;
	plane.coordinate.z = 0;
	plane.normal_vector.x = 0;
	plane.normal_vector.y = 1;
	plane.normal_vector.z = 0;
	normalize_vec(&plane.normal_vector);
	plane.color.r = 172;
	plane.color.g = 236;
	plane.color.b = 247;
	return (plane);
}

t_plane		init_plane2()
{
	t_plane	plane;

	plane.coordinate.x = 0;
	plane.coordinate.y = 5;
	plane.coordinate.z = 0;
	plane.normal_vector.x = 0;
	plane.normal_vector.y = 1;
	plane.normal_vector.z = 0;
	normalize_vec(&plane.normal_vector);
	plane.color.r = 235;
	plane.color.g = 210;
	plane.color.b = 180;
	return (plane);
}

t_plane		init_plane3()
{
	t_plane	plane;

	plane.coordinate.x = 5;
	plane.coordinate.y = 0;
	plane.coordinate.z = 0;
	plane.normal_vector.x = 1;
	plane.normal_vector.y = 0;
	plane.normal_vector.z = 0;
	normalize_vec(&plane.normal_vector);
	plane.color.r = 244;
	plane.color.g = 152;
	plane.color.b = 156;
	return (plane);
}

t_plane		init_plane4()
{
	t_plane	plane;

	plane.coordinate.x = 0;
	plane.coordinate.y = 0;
	plane.coordinate.z = 5;
	plane.normal_vector.x = 0;
	plane.normal_vector.y = 0;
	plane.normal_vector.z = 1;
	normalize_vec(&plane.normal_vector);
	plane.color.r = 218;
	plane.color.g = 196;
	plane.color.b = 247;
	return (plane);
}

t_plane		init_plane5()
{
	t_plane	plane;

	plane.coordinate.x = 0;
	plane.coordinate.y = 0;
	plane.coordinate.z = -5;
	plane.normal_vector.x = 0;
	plane.normal_vector.y = 0;
	plane.normal_vector.z = 1;
	normalize_vec(&plane.normal_vector);
	plane.color.r = 214;
	plane.color.g = 246;
	plane.color.b = 221;
	return (plane);
}

t_minirt_data	create_struct()
{
	t_minirt_data	test;

	test.sp_nb = 1;
	test.sphere_arr = malloc(sizeof(t_sphere) * 4);
	test.sphere_arr[0] = init_sphere();
	test.sphere_arr[1] = init_sphere2();
	test.sphere_arr[2] = init_sphere3();
	test.sphere_arr[3] = init_sphere4();

	test.pl_nb = 5;
	test.plane_arr = malloc(sizeof(t_plane) * 5);
	test.plane_arr[0] = init_plane();
	test.plane_arr[1] = init_plane2();
	test.plane_arr[2] = init_plane3();
	test.plane_arr[3] = init_plane4();
	test.plane_arr[4] = init_plane5();

	test.lt_nb = 1;
	test.lights_arr = malloc(sizeof(t_light));
	test.lights_arr[0] = init_light();
	return (test);
}
