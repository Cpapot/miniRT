/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:40:19 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:40:21 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/structure.h"
#include "../../libft/includes/libft.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

bool		fill_data(t_data *data_pt, char *file);
bool		read_fd_in_str(int fd, char **dst);
static bool	_is_rt_file(char *file_name);

bool	parsing(t_data *data_pt, char *file_name)
{
	int		fd;
	char	*file;

	if (_is_rt_file(file_name) == false)
		return (ft_printf_fd(2, "arguments must be a .rt file\n"), false);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("file_name"), false);
	if (read_fd_in_str(fd, &file) == false)
		return (close(fd), false);
	close(fd);
	return (fill_data(data_pt, file));
}

static bool	_is_rt_file(char *file_name)
{
	char	*tmp;

	tmp = ft_strrchr(file_name, '.');
	if (tmp == NULL \
		|| ft_strncmp(".rt", tmp, 4))
		return (false);
	return (true);
}
