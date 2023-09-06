#include "../../../../inc/structure.h"
#include "../../../../inc/filling_ft.h"

void	init_filling_ft(t_minirt_data * data_pt)
{
	fill_a(data_pt, INIT);
	fill_c(data_pt, INIT);
	fill_l(data_pt, INIT);
	fill_sp(data_pt, INIT);
	fill_pl(data_pt, INIT);
	fill_cy(data_pt, INIT);
    fill_co(data_pt, INIT);
    fill_di(data_pt, INIT);
}


bool	fill_a(void *data_pt, int flag)
{
	static t_ambient_light *ambient_light_arr;

	if (flag == INIT)
	{
		ambient_light_arr = ((t_minirt_data *)data_pt)->ambient_light;
		return (true);
	}
	ambient_light_arr->ratio = 0;
	if (get_line_data_a((char *)data_pt, ambient_light_arr) == false)
		return (false);
	ambient_light_arr++;
	return (true);
}

bool	fill_c(void *data_pt, int flag)
{
	static t_camera *camera_arr;

	if (flag == INIT)
	{
		camera_arr= ((t_minirt_data *)data_pt)->camera;
		return (true);
	}
	if (get_line_data_c((char *)data_pt, camera_arr) == false)
		return (false);
	camera_arr++;
	return (true);
}

bool	fill_l(void *data_pt, int flag)
{
	static t_light *light_arr;

	if (flag == INIT)
	{
		light_arr = ((t_minirt_data *)data_pt)->lights_arr;
		return (true);
	}
	if (get_line_data_l((char *)data_pt, light_arr) == false)
		return (false);
	light_arr++;
	return (true);
}

