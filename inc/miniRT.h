/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:03:42 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/11 13:31:32 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT
# define MINI_RT

# include "../libft/includes/libft.h"
# include "../mlx_lin/mlx.h"
# include <math.h>
# include <unistd.h>
/**/
# include <stdio.h>
/**/

# include "structure.h"
# include "window.h"
# include "vec3.h"

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
