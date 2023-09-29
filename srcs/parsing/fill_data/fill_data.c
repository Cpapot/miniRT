/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:07:46 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/26 20:01:09 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minirt_data.h"
#include "../../../libft/includes/libft.h"
#include "../../../inc/filling_ft.h"
#include "../../../inc/check_lines_ft.h"
#include "stdio.h"
#include <stddef.h>

#define PRINT_ERROR	"error filling this object line : "
#define ARE_YOU		"\nAre you sure about the value\n"

static bool	_check_lines(t_data *data_pt, char **lines);
static bool	_fill_lines_in_data(t_data *data_pt, char **lines);
static bool	_call_filling_ft(char **lines);
static bool	_line_is_false(char *line);
bool		warning_if_invalid_nb(t_data *data);

bool	fill_data(t_data *data_pt, char *file)
{
	char	**lines;

	lines = ft_split_no(file, '\n');
	free(file);
	if (!lines)
		return (perror("fill_data"), false);
	if (_check_lines(data_pt, lines) == false
		|| allocate_data(data_pt) == false)
		return (ft_free_split(lines), false);
	return (_fill_lines_in_data(data_pt, lines));
}

static bool	_fill_lines_in_data(t_data *data_pt, char **lines)
{
	init_filling_ft(data_pt);
	if (_call_filling_ft(lines) == false)
		return (false);
	return (true);
}

static bool	_call_filling_ft(char **lines)
{
	size_t					j;
	size_t					i;
	const t_filling_ft		ft_arr[] = {&fill_a, &fill_c, &fill_l, \
								&fill_sp, &fill_pl, &fill_cy, \
								&fill_co};
	const char				*id_arr[] = \
		{"A", "C", "L", "sp", "pl", "cy", "co"};

	j = -1;
	while (lines[++j])
	{
		i = 0;
		while (i < 8 && ft_strncmp(id_arr[i], \
					lines[j], ft_strlen(id_arr[i])) != 0)
			i++;
		if (i < 8 && ft_arr[i](lines[j], FILLING) == false)
		{
			ft_printf_fd(2, "error filling this object line : \
%d\n%s\nAre you sure about the value\n", j + 1, lines[j]);
			return (ft_free_split(lines), false);
		}
	}
	ft_free_split(lines);
	return (true);
}



static bool	_check_lines(t_data *data_pt, char **lines)
{
	int					j;
	int					i;
	const char			*id_arr[] = {"A", "C", "L", "sp", "pl", "cy"};
	const t_parse_ft	parse_ft_arr[] = {&manage_a, &manage_c, &manage_l,
		&manage_sp, &manage_pl, &manage_cy,
		&emmit_err};

	j = -1;
	while (lines[++j])
	{
		i = 0;
		while (i != 6 && ft_strncmp(id_arr[i], \
					lines[j], ft_strlen((char *)id_arr[i])) != 0)
			i++;
		if ((i < 6 && parse_ft_arr[i](data_pt, lines[j]) == false) \
			|| (i == 6 && _line_is_false(lines[j])))
			return (ft_printf_fd(2, "Error parsing: line %d\n%s\n", \
						j + 1, lines[j]), false);
	}
	if (warning_if_invalid_nb(data_pt))
		return (false);
	return (true);
}

static bool	_line_is_false(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (*line == '#')
		return (false);
	return (true);
}
