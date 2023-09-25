/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:03:42 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 16:02:53 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/includes/libft.h"
# include "../mlx_lin/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>

# include "structure.h"
# include "window.h"
# include "vec3.h"

int				close_window(void);
t_data			create_struct(void);
int32_t			check_ray(t_ray camray, t_data data, int level);
void			print_info(t_data *data);

typedef struct s_general
{
	t_data			data;
	t_mlx_info		win;
}	t_general;

#endif
