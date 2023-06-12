
#include "structures.h"

#include "fcntl.h"

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