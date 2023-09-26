/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:08:08 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:40:08 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/structure.h"
#include "../../../libft/includes/libft.h"

bool	skip_nb(char **line);

bool	check_float(char **line_pt)
{
	if (!ft_isdigit(**line_pt))
	{
		ft_printf_fd(2, "element must be float\n");
		return (false);
	}
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
	{
		ft_printf_fd(2, "Invalid coords\n");
		return (false);
	}
	nb = 3;
	while (--nb)
	{
		if (**line != ',')
		{
			ft_printf_fd(2, "Invalid coords\n");
			return (false);
		}
		*line = *line + 1;
		if (skip_nb(line) != true)
		{
			ft_printf_fd(2, "Invalid coords\n");
			return (false);
		}
	}
	return (true);
}

bool	vec_check(char **line)
{
	return (coord_check(line));
}
