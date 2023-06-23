/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:15:19 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/21 16:27:05 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

enum	e_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
};

typedef struct s_hitinfo
{
	double	t;
	int		type;
	void	*struct_info;
}			t_hitinfo;

void		ambient_lightning(t_color *ratio, t_minirt_data *data);
int			check_shadow(t_point hitpoint, t_light light, t_minirt_data *data);
t_hitinfo	find_close_object(t_ray camray, t_minirt_data data);

#endif
