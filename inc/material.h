/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:52:04 by cpapot            #+#    #+#             */
/*   Updated: 2023/08/01 21:53:22 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# define METAL {.reflection = 0.25, .specular_coef = 0.64, .alpha = 15, .is_board = false}
# define MIRROR {.reflection = 0, .specular_coef = 0, .alpha = 0, .is_board = false}
# define CHECKERBOARD {.reflection = 0, .specular_coef = 0, .alpha = 0, .is_board = true}
# define PLASTIC {.reflection = 0, .specular_coef = 0, .alpha = 0, .is_board = false}
# define BASIC {.reflection = 0, .specular_coef = 0, .alpha = 0, .is_board = false}

#endif
