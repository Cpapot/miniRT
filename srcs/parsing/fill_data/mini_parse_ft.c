/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:08:08 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:09:26 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/structure.h"
#include "../../../libft/includes/libft.h"

bool	space_incr(char **line_pt);

static bool	_rgb_error(void)
{
	ft_printf_fd(2, "Error rgb\n");
	return (false);
}

bool	rgb_check(char **line_pt)
{
	if (!ft_isdigit(**line_pt))
		return (_rgb_error());
	while (ft_isdigit(**line_pt))
		*line_pt = *line_pt + 1;
	if (**line_pt != ',')
		return (_rgb_error());
	*line_pt = *line_pt + 1;
	if (!ft_isdigit(**line_pt))
		return (_rgb_error());
	while (ft_isdigit(**line_pt))
		*line_pt = *line_pt + 1;
	if (**line_pt != ',')
		return (_rgb_error());
	*line_pt = *line_pt + 1;
	if (!ft_isdigit(**line_pt))
		return (_rgb_error());
	while (ft_isdigit(**line_pt))
		*line_pt = *line_pt + 1;
	return (true);
}

bool	check_empty(char **line)
{
	while (**line == ' ')
		*line = *line + 1;
	if (**line)
	{
		ft_printf_fd(2, "end line not empty.\n");
		return (false);
	}
	return (true);
}

bool	fov_check(char **line)
{
	if (ft_isdigit(**line) == false)
	{
		ft_printf_fd(2, "Fov must be digit\n");
		return (false);
	}
	while (ft_isdigit(**line))
		*line = *line + 1;
	return (true);
}

bool	check_for_material(char **line)
{
	const char	*str_arr[] = {"Plastic", "Metal", "Mirror", "Checkerboard"};
	int			i;
	int			len;

	while (**line != 0 && (**line == ' ' || **line == '\t'))
		*line = *line + 1;
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
	ft_printf_fd(2, "material not known :\n%s\n", *line);
	return (false);
}
