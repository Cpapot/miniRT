/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:03:42 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/14 15:44:01 by cpapot           ###   ########.fr       */
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

double			ft_find_light(t_vec_3 normal, t_light light);
t_minirt_data	create_struct();
int32_t			check_ray(t_ray camray, t_minirt_data data);



/**/


#endif
