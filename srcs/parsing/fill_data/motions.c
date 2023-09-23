#include "../../../inc/structure.h"
#include "../../../libft/includes/libft.h"

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
