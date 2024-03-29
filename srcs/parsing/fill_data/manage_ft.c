/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:08:08 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:09:17 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/structure.h"
#include "../../../inc/mini_parse_ft.h"
#include "unistd.h"

bool	manage_a(t_data *data_pt, char *line)
{
	size_t					i;
	const t_mini_parse_ft	parse_ft_arr[] = {
		&incr_one, &space_incr, &check_float, &space_incr,
		&rgb_check, &check_empty, NULL};

	data_pt->al_nb++;
	i = -1;
	while (++i < 6)
	{
		if (parse_ft_arr[i](&line) != true)
			return (false);
	}
	return (true);
}

bool	manage_c(t_data *data_pt, char *line)
{
	size_t					i;
	const t_mini_parse_ft	parse_ft_arr[] = {
		&incr_one, &space_incr, &coord_check, &space_incr, &vec_check,
		&space_incr, &fov_check, &check_empty, NULL};

	data_pt->ca_nb++;
	i = 0;
	while (parse_ft_arr[i])
	{
		if (parse_ft_arr[i](&line) != true)
			return (false);
		i++;
	}
	return (true);
}

bool	manage_l(t_data *data_pt, char *line)
{
	size_t					i;
	const t_mini_parse_ft	parse_ft_arr[] = {
		&incr_one, &space_incr, &coord_check, &space_incr, &check_float,
		&space_incr, &rgb_check, &check_for_material, &check_empty, NULL};

	data_pt->lt_nb++;
	i = 0;
	while (parse_ft_arr[i])
	{
		if (parse_ft_arr[i](&line) != true)
			return (false);
		i++;
	}
	return (true);
}

bool	emmit_err(t_data *data_pt, char *line)
{
	(void)data_pt;
	if (*line == 0 || *line == '#')
		return (true);
	if (write(2, "Invalid identifier\n", 19) == 0)
		return (false);
	return (false);
}
