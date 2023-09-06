#include "../../../../inc/structure.h"
#include "../../../../libft/includes/libft.h"
#include "../../../../inc/material.h"
#include "../../../../inc/go_to.h"

bool	ft_atod_on(char *line, double *dst);

bool	ft_material_on(char *line, t_material *dst)
{
	const char			*str_arr[] = {"Me", "Mi", "Ch", "Pl", ""};
	const t_material	material_arr[] = {METAL, MIRROR, \
					CHECKERBOARD, PLASTIC, BASIC};
	int					i;

	i = 0;
	while (i < 4 && ft_strncmp(str_arr[i], line, 2) != 0)
		i++;
	*dst = material_arr[i];
	return (true);
}

bool	ft_atorgb_on(char *line, t_color *dst)
{
	int	nb;

	nb = ft_atoi(line);
	if (nb < 0 || nb > 255)
		return (false);
	dst->r = nb;
	go_to_next_rgb(&line);
	nb = ft_atoi(line);
	if (nb < 0 || nb > 255)
		return (false);
	dst->g = nb;
	go_to_next_rgb(&line);
	nb = ft_atoi(line);
	if (nb < 0 || nb > 255)
		return (false);
	dst->b = nb;
	return (true);
}

bool	ft_atocoord_on(char *line, t_point *dst)
{
	if (ft_atod_on(line, &dst->x) == false)
		return (false);
	go_to_next_float(&line);
	if (ft_atod_on(line, &dst->y) == false)
		return (false);
	go_to_next_float(&line);
	if (ft_atod_on(line, &dst->z) == false)
		return (false);
	return (true);
}

bool	ft_atovec_on(char *line, t_vec_3 *dst)
{
	if (ft_atod_on(line, &dst->x) == false)
		return (false);
	go_to_next_float(&line);
	if (ft_atod_on(line, &dst->y) == false)
		return (false);
	go_to_next_float(&line);
	if (ft_atod_on(line, &dst->z) == false)
		return (false);
	return (true);
}
