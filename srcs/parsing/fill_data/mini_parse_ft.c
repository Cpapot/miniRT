#include "../../../inc/structure.h"
#include "../../../libft/includes/libft.h"

bool	space_incr(char **line_pt);

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
	const char	*str_arr[] = {"Plastic", "Metal", "Mirror", "Checkerboard"};
	int			i;
	int			len;

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
