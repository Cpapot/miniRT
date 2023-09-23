#include "../../../inc/structure.h"

#define INIT 0
#define FILLING 1

bool	fill_a(void *data_pt, int flag);
bool	fill_c(void *data_pt, int flag);
bool	fill_l(void *data_pt, int flag);
bool	fill_pl(void *data_pt, int flag);
bool	fill_sp(void *data_pt, int flag);
bool	fill_cy(void *data_pt, int flag);
bool	fill_co(void *data_pt, int flag);
bool	fill_di(void *data_pt, int flag);

bool	get_line_data_a(char *line, t_ambient_light *light_pt);
bool	get_line_data_c(char *line, t_camera *camera);
bool	get_line_data_l(char *line, t_light *light);

void	init_filling_ft(t_data *data_pt)
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
	static t_ambient_light	*ambient_light_arr;

	if (flag == INIT)
	{
		ambient_light_arr = ((t_data *)data_pt)->ambient_light;
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
	static t_camera	*camera_arr;

	if (flag == INIT)
	{
		camera_arr = ((t_data *)data_pt)->camera;
		return (true);
	}
	if (get_line_data_c((char *)data_pt, camera_arr) == false)
		return (false);
	camera_arr++;
	return (true);
}

bool	fill_l(void *data_pt, int flag)
{
	static t_light	*light_arr;

	if (flag == INIT)
	{
		light_arr = ((t_data *)data_pt)->lights_arr;
		return (true);
	}
	if (get_line_data_l((char *)data_pt, light_arr) == false)
		return (false);
	light_arr++;
	return (true);
}
