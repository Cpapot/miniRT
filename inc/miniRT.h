/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:03:42 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/12 21:06:06 by cpapot           ###   ########.fr       */
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

double	sphere_hited(t_ray camray, t_sphere sphere);
double	ft_find_light(t_vec_3 normal, t_light light);

/**/

typedef struct s_minirt_data	t_minirt_data;

struct s_minirt_data
{
	t_ambient_light	*ambient_light;
	t_camera		*camera;
	t_light			*lights_arr;
	t_sphere		*sphere_arr;
	t_plane			*plane_arr;
	t_cylinder		*cylinder_arr;
};

#endif
