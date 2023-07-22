#include "../inc/miniRT.h"

t_cone	init_cone()
{
	t_cone	result;

	result.diameter = 4;
	result.color.r = 255;
	result.color.g = 50;
	result.color.b = 50;
	result.coordinate.x = -3;
	result.coordinate.y = -2;
	result.coordinate.z = -4;
	result.vector = set_vec(0,1,0);
	result.height = 2;
	return (result);
}

t_minirt_data	create_struct()
{
	t_minirt_data	test;

	test.co_nb = 1;
	test.cone_arr = malloc(sizeof(t_cone));
	test.cone_arr[0] = init_cone();
	return (test);
}
