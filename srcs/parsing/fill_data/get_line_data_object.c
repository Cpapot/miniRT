/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_data_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:08:08 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/26 20:25:58 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/structure.h"
#include "../../../libft/includes/libft.h"

double	to_decimal(int tmp, char *line);
bool	ft_atof_on(char *line, double *dst);
bool	ft_material_on(char *line, t_material *dst);
double	to_decimal_ll(long long nb, char *line);
void	go_to_next_data(char **line_pt);
bool	ft_atocoord_on(char *line, t_point *dst);
bool	ft_atorgb_on(char *line, t_color *dst);
bool	ft_atofov_on(char *line, double *dst);
bool	ft_atoratio_on(char *line, double *dst);
bool	ft_atovec_on(char *line, t_vec_3 *dst);
bool	ft_atod_on(char *line, double *dst);

bool	get_line_data_sp(char *line, t_sphere *sphere)
{
	go_to_next_data(&line);
	if (ft_atocoord_on(line, &sphere->origin) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atod_on(line, &sphere->diameter) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atorgb_on(line, &sphere->color) == false)
		return (false);
	go_to_next_data(&line);
	return (ft_material_on(line, &sphere->material));
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
	if (ft_atorgb_on(line, &plane->color) == false)
		return (false);
	go_to_next_data(&line);
	return (ft_material_on(line, &plane->material));
}

bool	get_line_data_cy(char *line, t_cylinder *cylinder)
{
	go_to_next_data(&line);
	if (ft_atocoord_on(line, &cylinder->coord) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atovec_on(line, &cylinder->normal) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atod_on(line, &cylinder->diameter) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atod_on(line, &cylinder->height) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atorgb_on(line, &cylinder->color) == false)
		return (false);
	go_to_next_data(&line);
	return (ft_material_on(line, &cylinder->material));
}

bool	get_line_data_di(char *line, t_disk *disk)
{
	go_to_next_data(&line);
	if (ft_atocoord_on(line, &disk->coord) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atovec_on(line, &disk->normal) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atod_on(line, &disk->diameter) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atorgb_on(line, &disk->color) == false)
		return (false);
	go_to_next_data(&line);
	return (ft_material_on(line, &disk->material));
}

bool	get_line_data_co(char *line, t_cone *cone)
{
	go_to_next_data(&line);
	if (ft_atocoord_on(line, &cone->coordinate) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atovec_on(line, &cone->vector) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atod_on(line, &cone->diameter) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atod_on(line, &cone->height) == false)
		return (false);
	go_to_next_data(&line);
	if (ft_atorgb_on(line, &cone->color) == false)
		return (false);
	go_to_next_data(&line);
	return (ft_material_on(line, &cone->material));
}
