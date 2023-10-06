/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_data_ft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:08:08 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:08:29 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/structure.h"
#include "../../../libft/includes/libft.h"

void		_go_to_next_rgb(char **line);
void		_go_to_next_float(char **line);
bool		ft_atod_on(char *line, double *dst);
bool		ft_atof_on(char *line, double *dst);

t_material	polish(void);
t_material	metal(void);
t_material	mirror(void);
t_material	checker(void);
t_material	plastic(void);
t_material	basic(void);

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
	if (dst->z || dst->y || dst->x)
		return (true);
	ft_printf_fd(2, "Vector can't be 0,0,0\n");
	return (false);
}

bool	ft_atoratio_on(char *line, double *dst)
{
	if (ft_atod_on(line, dst) == false)
		return (false);
	if (*dst > 1 || *dst < 0)
		return (false);
	return (true);
}

bool	ft_material_on(char *line, t_material	*dst)
{
	int					i;
	static char			*str_arr[] = {"Me", "Mi", "Ch", "Pl", ""};
	const t_material	material_arr[] = {
		metal(), mirror(), checker(), plastic(), basic()
	};

	i = 0;
	while (i < 4 && ft_strncmp(str_arr[i], line, 2) != 0)
		i++;
	*dst = material_arr[i];
	return (true);
}
