/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:08:08 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:09:30 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		ft_printf_fd(2, "Non digit detected.\n");
		return (false);
	}
	while (ft_isdigit(**line))
		*line = *line + 1;
	if (**line == '.')
	{
		*line = *line + 1;
		if (ft_isdigit(**line) == false)
		{
			ft_printf_fd(2, "Non digit detected.\n");
			return (false);
		}
		while (ft_isdigit(**line))
			*line = *line + 1;
	}
	return (true);
}
