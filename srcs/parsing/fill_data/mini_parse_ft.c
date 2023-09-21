#include "../../../inc/structure.h"
#include "../../../libft/includes/libft.h"

bool	incr_one(char **line_pt)
{
	*line_pt = *line_pt + 1;
	return (true);
}

bool	space_incr(char **line_pt)
{
	if (**line_pt != ' ' && ** line_pt != '\t')
		return (false);
	while (**line_pt == ' ' && ** line_pt != '\t')
		*line_pt = *line_pt + 1;
	return (true);
}

bool	check_float(char **line_pt)
{
	if (!ft_isdigit(**line_pt))
		return (false);
	while (ft_isdigit(**line_pt))
		*line_pt = *line_pt + 1;
	if (**line_pt == '.') {
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
	if (**line == '.') {
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
	int	nb;

	if (skip_nb(line) != true)
		return (false);
	nb = 3;
	while (--nb) {
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

bool	check_for_material(char **line)
{
	char    *str_arr[] = {"Plastic", "Metal", "Mirror", "Checkerboard"};
	int     i;
	int     len;

	space_incr(line);
	if (**line == '\0')
		return (true);
	i = 0;
	while (i < 4)
	{
		len = ft_strlen(str_arr[i]);
		if (ft_strncmp(str_arr[i], *line, len) == 0)
		{
			*line = (*line) + len;
			return (true);
		}
		i++;
	}
	return (false);
}

