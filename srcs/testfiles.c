#include "../inc/miniRT.h"
/*
int32_t	test_color(t_point hitpoint)
{
	return (ft_color(100 * (hitpoint.x + 1), 100 * (hitpoint.y + 1), 100 * (hitpoint.z + 1), 10));
}*/

t_light		init_light()
{
	t_light	light;

	light.coordinate.x = 10;
	light.coordinate.y = 10;
	light.coordinate.z = 10;
	light.vector = set_vec(1, 1, 0);
	calculate_norm(&light.vector);
	return (light);
}

t_sphere	init_sphere()
{
	t_sphere	sphere;

	sphere.diameter = 3;
	sphere.origin.x = 0;
	sphere.origin.y = 0;
	sphere.origin.z = 0;
	sphere.color.r = 5;
	sphere.color.g = 100;
	sphere.color.b = 100;
	return (sphere);
}

t_sphere	init_sphere2()
{
	t_sphere	sphere;

	sphere.diameter = 3;
	sphere.origin.x = 3;
	sphere.origin.y = 0;
	sphere.origin.z = -0;
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


t_minirt_data	create_struct()
{
	t_minirt_data	test;

	test.sp_nb = 3;
	test.sphere_arr = malloc(sizeof(t_sphere) * 3);
	test.sphere_arr[0] = init_sphere();
	test.sphere_arr[1] = init_sphere2();
	test.sphere_arr[2] = init_sphere3();
	test.lights_arr = malloc(sizeof(t_light));
	test.lights_arr[0] = init_light();
	return (test);
}
