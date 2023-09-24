#include "../../../inc/minirt_data.h"
#include "../../../libft/includes/libft.h"
#include "../../../inc/filling_ft.h"
#include "../../../inc/check_lines_ft.h"
#include "stdio.h"
#include <stddef.h>

static bool	_check_lines(t_data *data_pt, char **lines);
static bool	_fill_lines_in_data(t_data *data_pt, char **lines);
static bool	_call_filling_ft(char **lines);

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
	puts("maps checked");
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
								&fill_co, &fill_di};
	const char				*id_arr[] = \
		{"A", "C", "L", "sp", "pl", "cy", "co", "di"};

	j = -1;
	while (lines[++j])
	{
		i = 0;
		while (i < 8 && ft_strncmp(id_arr[i], lines[j], ft_strlen(id_arr[i])) != 0)
			i++;
		if (i < 8 && ft_arr[i](lines[j], FILLING) == false)
		{
			ft_printf_fd(2, "error filling this object line : %d\n%s\nAre you sure about the value\n", j, lines[j]);
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
	const char			*id_arr[] = {
		"A", "C", "L", "sp", "pl", "cy", "di", "co"};
	const t_parse_ft	parse_ft_arr[] = {&manage_a, &manage_c, &manage_l,
		&manage_sp, &manage_pl, &manage_cy,
		&manage_di, &manage_co, &emmit_err};

	j = -1;
	while (lines[++j])
	{
		i = 0;
		while (i != 8
			&& ft_strncmp(id_arr[i], lines[j], ft_strlen((char *)id_arr[i])) != 0)
			i++;
		if (i < 8 && parse_ft_arr[i](data_pt, lines[j]) == false)
			return (ft_printf_fd(2, "Error parsing: line %d\n%s\n", j + 1, lines[j]), false);
	}
	if (data_pt->ca_nb == 0)
	{
		ft_printf_fd(2, "Error : .rt file must contain 1 camera\n");
		return (false);
	}
	return (true);
}
