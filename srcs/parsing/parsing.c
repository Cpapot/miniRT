#include "../../inc/structure.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

bool	fill_data(t_data *data_pt, char *file);
bool	read_fd_in_str(int fd, char **dst);

bool	parsing(t_data *data_pt, char *file_name)
{
	int		fd;
	char	*file;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("file_name"), false);
	if (read_fd_in_str(fd, &file) == false)
		return (close(fd), false);
	close(fd);
	return (fill_data(data_pt, file));
}
