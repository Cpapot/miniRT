#include "../../../inc/minirt_data.h"
#include "../../../libft/includes/libft.h"
#include "../../../inc/filling_ft.h"
#include "../../../inc/check_lines_ft.h"

static bool	_check_lines(t_minirt_data *data_pt, char **lines);
static bool	_fill_lines_in_data(t_minirt_data *data_pt, char **lines);
static bool	_call_filling_ft(char **lines);

bool	fill_data(t_minirt_data *data_pt, char *file)
{
	char	**lines;

	lines = ft_split_no(file, '\n');
	free(file);
	if (!lines)
		return (ft_printf_fd(2, "fill_data : error allocation\n"), false);
	if (_check_lines(data_pt, lines) == false \
			|| allocate_data(data_pt) == false)
		return (ft_free_split(lines), false);
	return (_fill_lines_in_data(data_pt, lines));
}

static bool	_check_lines(t_minirt_data *data_pt, char **lines)
{
	char				**tmp;
	int					i;
	const char			*id_arr[] = {"A", "C", "L", "sp", \
								"pl", "cy", "di", "co"};
	const t_parse_ft	parse_ft_arr[] = {&manage_a, &manage_c, &manage_l, \
										&manage_sp, &manage_pl, &manage_cy, \
										&manage_di, &manage_co, &emmit_err};

	tmp = lines;
	while (*tmp)
	{
		i = 0;
		while (i != 8 \
			&& ft_strncmp(id_arr[i], *tmp, ft_strlen((char *)id_arr[i])) != 0)
			i++;
		if (i < 8 && parse_ft_arr[i](data_pt, *tmp) == false)
			return (ft_printf_fd(2, "Error parsing\n"), false);
		tmp++;
	}
	if (data_pt->ca_nb == 0)
		return (false);
	return (true);
}

bool	_fill_lines_in_data(t_minirt_data *data_pt, char **lines)
{
	init_filling_ft(data_pt);
	if (_call_filling_ft(lines) == false)
		return (false);
	return (true);
}

static bool	_call_filling_ft(char **lines)
{
	size_t				i;
	char				**tmp;
	const char			*id_arr[] = {"A", "C", "L", "sp", \
								"pl", "cy", "co", "di"};
	const t_filling_ft	ft_arr[] = {&fill_a, &fill_c, &fill_l, \
								&fill_sp, &fill_pl, &fill_cy, \
								&fill_co, &fill_di};

	tmp = lines;
	while (*tmp)
	{
		i = 0;
		while (i < 8 && ft_strncmp(id_arr[i], *tmp, ft_strlen(id_arr[i])) != 0)
			i++;
		if (i < 8 && ft_arr[i](*tmp, FILLING) == false)
			return (ft_free_split(lines), false);
		tmp++;
	}
	ft_free_split(lines);
	return (true);
}
