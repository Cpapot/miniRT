#include "../../../../libft/includes/libft.h"

void	go_to_next_data(char **line_pt)
{
	while (**line_pt != ' ' && **line_pt != '\t')
		*line_pt = (*line_pt) + 1;
	while (**line_pt == ' ' || **line_pt == '\t')
		*line_pt = (*line_pt) + 1;
}

void	go_to_next_float(char **line)
{
	if (**line == '-')
		*line = (*line) + 1;
	while (ft_isdigit(**line) || **line == '.')
		*line = (*line) + 1;
	*line = (*line) + 1;
}

void	go_to_next_rgb(char **line)
{
	while (ft_isdigit(**line))
		*line = (*line) + 1;
	*line = (*line) + 1;
}

void	go_to_decimal_part(char **line)
{
	if (**line == '-')
		*line = (*line) + 1;
	while (ft_isdigit(**line))
		*line = (*line) + 1;
	if (**line == '.')
		*line = (*line) + 1;
}
