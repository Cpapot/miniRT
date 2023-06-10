/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:03:42 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/10 19:13:10 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT
# define MINI_RT

# include "../libft/includes/libft.h"
# include "../srcs/parsing/structures.h"
# include "../mlx_lin/mlx.h"
# include "window.h"

# include <math.h>
# include <unistd.h>

# define M_PI		3.141592
/**/
# include <stdio.h>
/**/

t_vec_3		adding_vec(t_vec_3 vec1, t_vec_3 vec2)
t_vec_3		set_vec(double x, double y, double z);
t_vec_3		scalar_product(t_vec_3 vec1, t_vec_3 vec2);
t_vec_3		*multiplying_vec(t_vec_3 *vec, double factor);
double		calculate_norm(t_vec_3 *vec);
void		normalize_vec(t_vec_3 *vec);

#endif
