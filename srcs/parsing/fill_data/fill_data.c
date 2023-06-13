//
// Created by bpoumeau on 6/9/23.
//

#include "structure.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"
#include "unistd.h"

static	bool	_check_lines(t_minirt_data *data_pt, char **lines);
char 			**ft_split(char *str, char delim);
char 			*ft_strstr(char *s1, char *s2);
bool			ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (false);
	return (true);
}

size_t 			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int 			ft_strncmp(const char *s1, const char *s2, size_t len);


bool	fill_data(t_minirt_data *data_pt, char *file)
{
	char	**lines;

	lines = ft_split(file, '\n');
	free(file);
	if (!lines)
		return (perror("fill_data"), false);
	if (_check_lines(data_pt, lines) == false)
		return (false);
	//if (_allocate_data(data_pt, lines) == false)
		//return (false);
	//fill_lines_in_data(data_pt, lines);
	return (true);
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
	puts("check float");
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
	printf("rgb check\n");
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
	puts("i skip");
	if (**line == '-')
		*line = *line + 1;
	if (ft_isdigit(**line) == false)
		return (false);
	puts("post digit");
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
	puts("return true");
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
		printf("je test -%s-\n", *line);
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

	printf("A parser\n");
	data_pt->al_nb++;
	i = -1;
	while (++i < 6)
	{
		printf("%ld\n", i);
		printf("-%s-\n", line);
		if (parse_ft_arr[i](&line) != true)
			return (false);
	}
	return (true);
}

bool	manage_c(t_minirt_data *data_pt, char *line)
{
	const	t_mini_parse_ft parse_ft_arr[] = {&incr_one, &space_incr, &coord_check, &space_incr, &vec_check, &space_incr, &fov_check, &check_empty, NULL};
	size_t i;

	puts("C");
	data_pt->al_nb++;
	i = 0;
	while (parse_ft_arr[i])
	{
		printf("%ld -%s-\n", i, line);
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

	data_pt->al_nb++;
	i = 0;
	while (parse_ft_arr[i])
	{
		printf("%ld -%s-\n", i, line);
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

	data_pt->al_nb++;
	i = 0;
	while (parse_ft_arr[i])
	{
		printf("%ld -%s-\n", i, line);
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

	data_pt->al_nb++;
	i = 0;
	while (parse_ft_arr[i])
	{
		printf("%ld -%s-\n", i, line);
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

	data_pt->al_nb++;
	i = 0;
	while (parse_ft_arr[i])
	{
		printf("%ld -%s-\n", i, line);
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
	write(2, "Invalid identifier\n", 19);
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
	const char	*id_arr[] = {"A", "C", "L", "sp", "pl","cy"};
	const t_parse_ft parse_ft_arr[] = {&manage_a, &manage_c, &manage_l, &manage_sp, &manage_pl, &manage_cy, &emmit_err};

	tmp = lines;
	while (*tmp)
	{
		i = 0;
		while (ft_strncmp(id_arr[i], *tmp, ft_strlen((char *)id_arr[i])) != 0 && i != 6)
			i++;
		if (parse_ft_arr[i](data_pt, *tmp) == false)
			return (write(2, "Error parsing\n", 14), false);
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