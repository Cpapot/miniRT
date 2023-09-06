#include "../../../../inc/structure.h"
#include "../../../../inc/filling_ft.h"

bool	fill_sp(void *data_pt, int flag)
{
	static t_sphere	*sphere_arr;

	if (flag == INIT)
	{
		sphere_arr = ((t_minirt_data *)data_pt)->sphere_arr;
		return (true);
	}
	if (get_line_data_sp((char *)data_pt, sphere_arr) == false)
		return (false);
	sphere_arr++;
	return (true);
}

bool	fill_pl(void *data_pt, int flag)
{
	static t_plane	*plane_arr;

	if (flag == INIT)
	{
		plane_arr = ((t_minirt_data *)data_pt)->plane_arr;
		return (true);
	}
	if (get_line_data_pl((char *)data_pt, plane_arr) == false)
		return (false);
	plane_arr++;
	return (true);
}

bool	fill_cy(void *data_pt, int flag)
{
	static t_cylinder	*cylinder_arr;

	if (flag == INIT)
	{
		cylinder_arr = ((t_minirt_data *)data_pt)->cylinder_arr;
		return (true);
	}
	if (get_line_data_cy((char *)data_pt, cylinder_arr) == false)
		return (false);
	cylinder_arr++;
	return (true);
}

bool	fill_di(void *data_pt, int flag)
{
	static t_disk	*disk_arr;

	if (flag == INIT)
	{
		disk_arr = ((t_minirt_data *)data_pt)->disk_arr;
		return (true);
	}
	if (get_line_data_di((char *)data_pt, disk_arr) == false)
		return (false);
	disk_arr++;
	return (true);
}

bool	fill_co(void *data_pt, int flag)
{
	static t_cone	*cone_arr;

	if (flag == INIT)
	{
		cone_arr = ((t_minirt_data *)data_pt)->cone_arr;
		return (true);
	}
	if (get_line_data_co((char *)data_pt, cone_arr) == false)
		return (false);
	cone_arr++;
	return (true);
}
