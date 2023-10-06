/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_data_motions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:08:08 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:08:43 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"

void	go_to_next_data(char **line_pt)
{
	while (**line_pt && **line_pt != ' ' && **line_pt != '\t')
		*line_pt = (*line_pt) + 1;
	while (**line_pt && (**line_pt == ' ' || **line_pt == '\t'))
		*line_pt = (*line_pt) + 1;
}

void	_go_to_next_rgb(char **line)
{
	while (ft_isdigit(**line))
		*line = (*line) + 1;
	*line = (*line) + 1;
}

void	_go_to_next_float(char **line)
{
	if (**line == '-')
		*line = (*line) + 1;
	while (ft_isdigit(**line) || **line == '.')
		*line = (*line) + 1;
	*line = (*line) + 1;
}

void	_go_to_decimal_part(char **line)
{
	if (**line == '-')
		*line = (*line) + 1;
	while (ft_isdigit(**line))
		*line = (*line) + 1;
	if (**line == '.')
		*line = (*line) + 1;
}
