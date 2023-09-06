#include "../../../../inc/structure.h"
#include "../../../../libft/includes/libft.h"

bool	incr_one(char **line_pt)
{
	*line_pt = *line_pt + 1;
	return (true);
}

bool	space_incr(char **line_pt)
{
	if (**line_pt != ' ' && **line_pt != '\t')
		return (false);
	while (**line_pt == ' ' && **line_pt != '\t')
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

bool	check_empty(char **line)
{
	while (**line == ' ')
		*line = *line + 1;
	if (**line)
		return (false);
	return (true);
}
