
#include "structure.h"
#include "fcntl.h"
#include "stdbool.h"
#include "stdio.h"
#include "unistd.h"

bool	fill_data(t_minirt_data *data_pt, char *file);
bool	read_all_in(int fd, char **file_pt);

bool	parsing(t_minirt_data *data_pt, char *file_name)
{
	int		fd;
	char	*file;

	fd = open(file_name, O_WRONLY);
	if (fd == -1)
		return (perror("file_name"), false);
	if (read_all_in(fd, &file) == false)
		return (close(fd), false);
	close(fd);
	return (fill_data(data_pt, file));
}