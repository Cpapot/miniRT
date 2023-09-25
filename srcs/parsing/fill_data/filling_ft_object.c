/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_ft_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:08:08 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:08:10 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/structure.h"

#define INIT 0
#define FILLING 1

bool	get_line_data_sp(char *line, t_sphere *sphere);
bool	get_line_data_pl(char *line, t_plane *plane);
bool	get_line_data_cy(char *line, t_cylinder *cylinder);
bool	get_line_data_co(char *line, t_cone *cone);
bool	get_line_data_di(char *line, t_disk *disk);
bool	fill_pl(void *data_pt, int flag);
bool	fill_sp(void *data_pt, int flag);
bool	fill_cy(void *data_pt, int flag);
bool	fill_co(void *data_pt, int flag);
bool	fill_di(void *data_pt, int flag);

bool	fill_di(void *data_pt, int flag)
{
	static t_disk	*disk_arr;

	if (flag == INIT)
	{
		disk_arr = ((t_data *)data_pt)->disk_arr;
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
		cone_arr = ((t_data *)data_pt)->cone_arr;
		return (true);
	}
	if (get_line_data_co((char *)data_pt, cone_arr) == false)
		return (false);
	cone_arr++;
	return (true);
}

bool	fill_sp(void *data_pt, int flag)
{
	static t_sphere	*sphere_arr;

	if (flag == INIT)
	{
		sphere_arr = ((t_data *)data_pt)->sphere_arr;
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
		plane_arr = ((t_data *)data_pt)->plane_arr;
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
		cylinder_arr = ((t_data *)data_pt)->cylinder_arr;
		return (true);
	}
	if (get_line_data_cy((char *)data_pt, cylinder_arr) == false)
		return (false);
	cylinder_arr++;
	return (true);
}
