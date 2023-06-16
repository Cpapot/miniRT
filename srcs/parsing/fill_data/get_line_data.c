//
// Created by bpoumeau on 6/13/23.
//

#include <structure.h>
#include <libft.h>
#include "stdio.h"

static void	_go_to_decimal_part(char **line)
{
	if (**line == '-')
		*line = (*line) + 1;
	while (ft_isdigit(**line))
		*line = (*line) + 1;
	if (**line == '.')
		*line = (*line) + 1;
}

float	to_decimal(int tmp, char *line)
{
	float	dst;

	dst = tmp;
	while (ft_isdigit(*line))
	{
		dst /= 10;
		line++;
	}
	return (dst);
}

bool	ft_atof_on(char *line, float *dst)
{
	int 	integer;
	int 	tmp;
	float	decimal;

	if (ft_atoi_on(line, &integer) == false)
		return (false);
	_go_to_decimal_part(&line);
	if (ft_atoi_on(line, &tmp) == false)
		return (false);
	decimal = to_decimal(tmp, line);
	if (integer < 0)
		decimal -= integer;
	else
		decimal += integer;
	*dst = decimal;
	return (true);

}

double to_decimal_ll(long long nb, char *line)
{
	double dst;

	dst = nb;
	while (ft_isdigit(*line))
	{
		line++;
		dst /= 10;
	}
	return (dst);
}

bool	ft_atod_on(char *line, double *dst)
{
	long long	integer;
	long long	tmp;
	double		decimal;

	tmp = 0;
	if (ft_atoll_on(line, &integer) == false)
		return (false);
	_go_to_decimal_part(&line);
	if (*line != ' ' && ft_atoll_on(line, &tmp) == false)
		return (false);
	if (integer > 0)
		decimal = to_decimal_ll(tmp, line) + integer;
	else
		decimal = integer - to_decimal_ll(tmp, line);
	*dst = decimal;
	return (true);
}

void	go_to_next_data(char **line_pt)
{
	while (**line_pt != ' ')
		*line_pt = (*line_pt) + 1;
	while (**line_pt == ' ')
		*line_pt = (*line_pt) + 1;
}

void	_go_to_next_rgb(char **line)
{
	while (ft_isdigit(**line))
		*line = (*line) + 1;
	*line = (*line) + 1;
}

bool	ft_atorgb_on(char *line, t_color *dst)
{
	int	nb;

	nb = ft_atoi(line);
	if (nb < 0 || nb > 255)
		return (false);
	dst->r = nb;
	_go_to_next_rgb(&line);
	nb = ft_atoi(line);
	if (nb < 0 || nb > 255)
		return (false);
	dst->g = nb;
	_go_to_next_rgb(&line);
	nb = ft_atoi(line);
	if (nb < 0 || nb > 255)
		return (false);
	dst->b = nb;
	return (true);
}

void	_go_to_next_float(char **line)
{
	if (**line == '-')
		*line = (*line) + 1;
	while (ft_isdigit(**line) || **line == '.')
		*line = (*line) + 1;
	*line = (*line) + 1;
}

void	print_point(t_point point);
bool	ft_atocoord_on(char *line, t_point *dst)
{
	if (ft_atod_on(line, &dst->x) == false)
		return (false);
	_go_to_next_float(&line);
	if (ft_atod_on(line, &dst->y) == false)
		return (false);
	_go_to_next_float(&line);
	if (ft_atod_on(line, &dst->z) == false)
		return (false);
	return (true);
}

void	print_vector(t_vec_3 vector);
bool	ft_atovec_on(char *line, t_vec_3 *dst)
{
	if (ft_atod_on(line, &dst->x) == false)
		return (false);
	_go_to_next_float(&line);
	if (ft_atod_on(line, &dst->y) == false)
		return (false);
	_go_to_next_float(&line);
	if (ft_atod_on(line, &dst->z) == false)
		return (false);
	if (dst->x > 1 || dst->y > 1 || dst->z > 1)
		return (false);
	print_vector(*dst);
	return (true);
}

bool	ft_atofov_on(char *line, float *dst)
{
	if (ft_atof_on(line, dst) == false)
		return (false);
	if (*dst > 180 || *dst < 0)
		return (false);
	return (true);
}

bool	ft_atoratio_on(char *line, float *dst)
{
	if (ft_atof_on(line, dst) == false)
		return (false);
	if (*dst > 1 || *dst < 0)
		return (false);
	return (true);
}

bool	get_line_data_a(char *line, t_ambient_light *light_pt)
{
	while (ft_isdigit(*line) == false)
		line++;
	if (ft_atof_on(line, &(light_pt->ratio)) == false)
		return (false);
	go_to_next_data(&line);
	return (ft_atorgb_on(line, &(light_pt->color)));
}

bool	get_line_data_c(char *line, t_camera *camera)
{
	go_to_next_data(&line);
	if (ft_atocoord_on(line, &camera->origin) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atovec_on(line, &camera->vector) == false)
		return (false);
	go_to_next_data(&line);
	return (ft_atofov_on(line, &camera->fov));
}

bool	get_line_data_l(char *line, t_light *light)
{
	go_to_next_data(&line);
	if (ft_atocoord_on(line, &light->coordinate) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atoratio_on(line, &light->brightness) == false)
		return (false);
	go_to_next_data(&line);
	return (ft_atorgb_on(line, &light->color));
}

bool	get_line_data_sp(char *line, t_sphere *sphere)
{
	go_to_next_data(&line);
	if (ft_atocoord_on(line, &sphere->origin) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atod_on(line, &sphere->diameter) == false)
		return (false);
	go_to_next_data(&line);
	return (ft_atorgb_on(line, &sphere->color));
}

bool	get_line_data_pl(char *line, t_plane *plane)
{
	go_to_next_data(&line);
	if (ft_atocoord_on(line, &plane->coordinate) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atovec_on(line, &plane->normal_vector) == false)
		return (false);
	go_to_next_data(&line);
	return (ft_atorgb_on(line, &plane->color));
}

bool	get_line_data_cy(char *line, t_cylinder *cylinder)
{
	go_to_next_data(&line);
	if (ft_atocoord_on(line, &cylinder->coordinate) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atovec_on(line, &cylinder->normal_vector) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atod_on(line, &cylinder->diameter) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atod_on(line, &cylinder->height) == false)
		return (false);
	go_to_next_data(&line);
	return (ft_atorgb_on(line, &cylinder->color));
}
