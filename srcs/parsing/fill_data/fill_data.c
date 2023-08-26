//
// Created by bpoumeau on 6/9/23.
//

#include "../../../inc/structure.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "../../../libft/includes/libft.h"
#include "../../../inc/minirt_data.h"

#define INIT 0
#define FILLING 1

bool	fill_a(void *data_pt, int flag);
bool	fill_c(void *data_pt, int flag);
bool	fill_l(void *data_pt, int flag);
bool	fill_pl(void *data_pt, int flag);
bool	fill_sp(void *data_pt, int flag);
bool	fill_cy(void *data_pt, int flag);

static	bool	_check_lines(t_minirt_data *data_pt, char **lines);
void	init_filling_ft(t_minirt_data * data_pt);

typedef bool	(*t_filling_ft)(void *data_pt, int flag);

bool	call_filling_ft(char **lines)
{
	const	t_filling_ft	ft_arr[] = {&fill_a, &fill_c, &fill_l, &fill_sp, &fill_pl, &fill_cy};
	const	char			*id_arr[] = {"A", "C", "L", "sp", "pl", "cy"};
	size_t	i;
	char 	**tmp;

	tmp = lines;
	size_t nb = 0;
	while (*tmp)
	{
		nb++;
		i = 0;
		while (i < 6 && ft_strncmp(id_arr[i], *tmp, ft_strlen(id_arr[i])) != 0)
			i++;
		if (i < 6 && ft_arr[i](*tmp, FILLING) == false)
			return (ft_free_split(lines), false);
		tmp++;
	}
    puts("here");
	ft_free_split(lines);
	return (true);
}

bool	fill_lines_in_data(t_minirt_data *data_pt, char **lines)
{
	init_filling_ft(data_pt);
	if (call_filling_ft(lines) == false)
		return (free_minirt_data_content(data_pt), false);
	return (true);
}


bool	fill_data(t_minirt_data *data_pt, char *file)
{
	char	**lines;

	lines = ft_split_no(file, '\n');
	free(file);
	if (!lines)
		return (perror("fill_data"), false);
	if (_check_lines(data_pt, lines) == false)
		return (false);
	if (allocate_data(data_pt) == false)
		return (false);
	return (fill_lines_in_data(data_pt, lines));
}

typedef bool	(*t_parse_ft)(t_minirt_data *data_pt, char *line);
typedef bool	(*t_mini_parse_ft)(char **line_pt);

bool	incr_one(char **line_pt)
{
	*line_pt = *line_pt + 1;
	return (true);
}

bool	space_incr(char **line_pt)
{
	if (**line_pt != ' ')
		return (false);
	while (**line_pt == ' ')
		*line_pt = *line_pt + 1;
	return (true);
}

bool	check_float(char **line_pt)
{
	if (!ft_isdigit(**line_pt))
		return (false);
	while (ft_isdigit(**line_pt))
		*line_pt = *line_pt + 1;
	if (**line_pt == '.')
	{
		*line_pt = *line_pt + 1;
		while (ft_isdigit(**line_pt))
			*line_pt = *line_pt + 1;
	}
	return (true);
}

bool	rgb_check(char **line_pt)
{
	if (!ft_isdigit(**line_pt))
		return (false);
	while (ft_isdigit(**line_pt))
		*line_pt = *line_pt + 1;
	if (**line_pt != ',')
		return (false);
	*line_pt = *line_pt + 1;
	if (!ft_isdigit(**line_pt))
		return (false);
	while (ft_isdigit(**line_pt))
		*line_pt = *line_pt + 1;
	if (**line_pt != ',')
		return (false);
	*line_pt = *line_pt + 1;
	if (!ft_isdigit(**line_pt))
		return (false);
	while (ft_isdigit(**line_pt))
		*line_pt = *line_pt + 1;
	return (true);
}

bool	skip_nb(char **line)
{
	if (**line == '-')
		*line = *line + 1;
	if (ft_isdigit(**line) == false)
		return (false);
	while (ft_isdigit(**line))
		*line = *line + 1;
	if (**line == '.')
	{
		*line = *line + 1;
		if (ft_isdigit(**line) == false)
			return (false);
		while (ft_isdigit(**line))
			*line = *line + 1;
	}
	return (true);
}

bool	coord_check(char **line)
{
	int nb;

	if (skip_nb(line) != true)
		return (false);
	nb = 3;
	while (--nb)
	{
		if (**line != ',')
			return (false);
		*line = *line + 1;
		if (skip_nb(line) != true)
			return (false);
	}
	return (true);
}

bool	vec_check(char **line)
{
	return (coord_check(line));
}

bool	check_empty(char **line)
{
	while (**line == ' ')
		*line = *line + 1;
	if (**line)
		return (false);
	return (true);
}

bool	fov_check(char **line)
{
	if (ft_isdigit(**line) == false)
		return (false);
	while (ft_isdigit(**line))
		*line = *line + 1;
	if (**line == ' ' || **line == 0)
		return (true);
	return (false);
}

bool	manage_a(t_minirt_data *data_pt, char *line)
{
	const	t_mini_parse_ft parse_ft_arr[] = {&incr_one, &space_incr, &check_float, &space_incr, &rgb_check, &check_empty, NULL};
	size_t i;

	data_pt->al_nb++;
	i = -1;
	while (++i < 6)
	{
		if (parse_ft_arr[i](&line) != true)
			return (false);
	}
	return (true);
}

bool	manage_c(t_minirt_data *data_pt, char *line)
{
	const	t_mini_parse_ft parse_ft_arr[] = {&incr_one, &space_incr, &coord_check, &space_incr, &vec_check, &space_incr, &fov_check, &check_empty, NULL};
	size_t i;

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

bool	manage_l(t_minirt_data *data_pt, char *line)
{
	const	t_mini_parse_ft parse_ft_arr[] = {&incr_one, &space_incr, &coord_check, &space_incr, &check_float, &space_incr, &rgb_check, &check_empty, NULL};
	size_t i;

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

bool	manage_sp(t_minirt_data *data_pt, char *line)
{
	const	t_mini_parse_ft parse_ft_arr[] = {&incr_one, &incr_one, &space_incr, &coord_check, &space_incr, &check_float, &space_incr, &rgb_check, &check_empty, NULL};
	size_t i;

	data_pt->sp_nb++;
	i = 0;
	while (parse_ft_arr[i])
	{
		if (parse_ft_arr[i](&line) != true)
			return (false);
		i++;
	}
	return (true);
}

bool	manage_pl(t_minirt_data *data_pt, char *line)
{
	const	t_mini_parse_ft parse_ft_arr[] = {&incr_one, &incr_one, &space_incr, &coord_check, &space_incr, &vec_check, &space_incr, &rgb_check, &check_empty, NULL};
	size_t i;

	data_pt->pl_nb++;
	i = 0;
	while (parse_ft_arr[i])
	{
		if (parse_ft_arr[i](&line) != true)
			return (false);
		i++;
	}
	return (true);
}

bool	manage_cy(t_minirt_data *data_pt, char *line)
{
	const	t_mini_parse_ft parse_ft_arr[] = {&incr_one, &incr_one, &space_incr, &coord_check, &space_incr, &vec_check, &space_incr, &check_float, &space_incr, &check_float, &space_incr, &rgb_check,
											   &check_empty, NULL};
	size_t i;

	data_pt->cy_nb++;
	i = 0;
	while (parse_ft_arr[i])
	{
		if (parse_ft_arr[i](&line) != true)
			return (false);
		i++;
	}
	return (true);
}

bool	emmit_err(t_minirt_data *data_pt, char *line)
{
	(void)data_pt;
	if (*line == 0)
		return (true);
	ft_printf_fd(2, "Invalid identifier\n");
	return (false);
}

bool	do_nothing(t_minirt_data *data_pt, char *line)
{
	(void)data_pt;
	(void)line;
	return (true);
}


static bool	_check_lines(t_minirt_data  *data_pt, char **lines)
{
	char		**tmp;
	int 		i;
	const char	*id_arr[] = {"A", "C", "L", "sp", "pl","cy", "#", "\n"};
	const t_parse_ft parse_ft_arr[] = {&manage_a, &manage_c, &manage_l, &manage_sp, &manage_pl, &manage_cy, &emmit_err};

    i = 0;
	tmp = lines;
	while (*tmp)
	{
		i = 0;
		while (i != 7 && ft_strncmp(id_arr[i], *tmp, ft_strlen((char *)id_arr[i])) != 0)
			i++;
		if (i < 6 && parse_ft_arr[i](data_pt, *tmp) == false)
			return (ft_printf_fd(2, "Error parsing\n"), false);
		tmp++;
	}
	return (true);
}

#ifdef TEST

#include "readline/readline.h"

int main(int ac, char **av)
{
	char **lines = malloc(sizeof(char *) * 2);
	t_minirt_data 	data;

	while (1)
	{
		*lines = readline("line : ");
		*(lines + 1) = NULL;
		_check_lines(&data, lines);
	}
}
#endif
