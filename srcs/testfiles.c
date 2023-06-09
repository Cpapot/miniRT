#include "../inc/miniRT.h"

t_cone	init_cone()
{
	t_cone	result;

	result.diameter = 2;
	result.color.r = 255;
	result.color.g = 50;
	result.color.b = 50;
	result.coordinate.x = 0;
	result.coordinate.y = 0;
	result.coordinate.z = 0;
	result.vector = set_vec(1,1,0);
	result.height = 1;
	return (result);
}

t_minirt_data	create_struct()
{
	t_minirt_data	test;

	test.co_nb = 0;
	test.cone_arr = malloc(sizeof(t_cone));
	test.cone_arr[0] = init_cone();
	return (test);
}
