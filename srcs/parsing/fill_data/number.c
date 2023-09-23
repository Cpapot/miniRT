#include "../../../inc/structure.h"
#include "../../../libft/includes/libft.h"

bool	skip_nb(char **line);

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

bool	coord_check(char **line)
{
	int	nb;

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
