/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:15:19 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/14 16:41:22 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

enum	e_type
{
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_hitinfo
{
	double	t;
	int		type;
	void	*struct_info;
}			t_hitinfo;

#endif
