/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:08:08 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:09:07 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/structure.h"
#include "../../../libft/includes/libft.h"

bool	ft_atod_on(char *line, double *dst);
bool	ft_atof_on(char *line, double *dst);
bool	ft_atorgb_on(char *line, t_color *dst);
bool	ft_atovec_on(char *line, t_vec_3 *dst);
bool	ft_atoratio_on(char *line, double *dst);
bool	ft_atofov_on(char *line, double *dst);
bool	ft_atocoord_on(char *line, t_point *dst);
double	to_decimal(int tmp, char *line);

void	_go_to_next_rgb(char **line);
void	_go_to_next_float(char **line);
void	_go_to_decimal_part(char **line);
void	go_to_next_data(char **line_pt);

bool	get_line_data_a(char *line, t_ambient_light *light_pt)
{
	while (ft_isdigit(*line) == false)
		line++;
	if (ft_atod_on(line, &(light_pt->ratio)) == false)
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
