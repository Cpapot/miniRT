#include "../../../../inc/structure.h"
#include "../../../../libft/includes/libft.h"
#include "../../../../inc/get_lines_ft.h"
#include <stdio.h>

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

