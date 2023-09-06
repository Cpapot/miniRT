#include "../../../../inc/structure.h"
#include "../../../../libft/includes/libft.h"
#include "../../../../inc/get_lines_ft.h"
#include <stdio.h>

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
    if (ft_atorgb_on(line, &cylinder->color) == false)
        return (false);
    go_to_next_data(&line);
    return (ft_material_on(line, &cylinder->material));
}

bool    get_line_data_di(char *line, t_disk *disk)
{
    go_to_next_data(&line);
    if (ft_atocoord_on(line, &disk->coordinate) == false)
        return (false);
    go_to_next_data(&line);
	if (ft_atovec_on(line, &disk->normal_vector) == false)
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

bool    get_line_data_co(char *line, t_cone *cone)
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
