/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:03:42 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/17 18:56:20 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT
# define MINI_RT

# include "../libft/includes/libft.h"
# include "../mlx_lin/mlx.h"
# include <math.h>
# include <unistd.h>


# include "structure.h"
# include "window.h"
# include "vec3.h"

/**/
# include <stdio.h>
# include "sphere.h"
# include "plane.h"

t_minirt_data	create_struct();
int32_t			check_ray(t_ray camray, t_minirt_data data);
t_color			ft_find_light_ratio(t_point hitpoint, t_minirt_data data, t_vec_3 normal);
void		print_info(t_minirt_data *data);

typedef struct s_general
{
	t_minirt_data	data;
	t_mlx_info		win;
} t_general;

/**/


#endif
