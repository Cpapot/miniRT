#include "../../../../inc/structure.h"
#include "../../../../inc/mini_parse_ft.h"
#include "../../../../libft/includes/libft.h"

bool	manage_a(t_minirt_data *data_pt, char *line)
{
	const t_mini_parse_ft	parse_ft_arr[] = {
		&incr_one, &space_incr, &check_float, &space_incr, \
		&rgb_check, &check_empty, NULL};
	size_t					i;

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
	const t_mini_parse_ft	parse_ft_arr[] = {
		&incr_one, &space_incr, &coord_check, &space_incr, &vec_check, \
		&space_incr, &fov_check, &check_empty, NULL};
	size_t					i;

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
	const t_mini_parse_ft	parse_ft_arr[] = {
		&incr_one, &space_incr, &coord_check, &space_incr, &check_float, \
		&space_incr, &rgb_check, &check_for_material, &check_empty, NULL};
	size_t					i;

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

bool	emmit_err(t_minirt_data *data_pt, char *line)
{
	(void)data_pt;
	if (*line == 0 || *line == '#')
		return (true);
	ft_printf_fd(2, "invalid identifier");
	return (false);
}
