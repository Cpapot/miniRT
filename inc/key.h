/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:53:11 by cpapot            #+#    #+#             */
/*   Updated: 2023/06/17 03:05:49 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H

# define KEY_H

#include "structure.h"

#  define KB_ESC		65307
#  define KB_W			122
#  define KB_A			113
#  define KB_S			115
#  define KB_D			100
#  define KB_UP			65362
#  define KB_DOWN		65364
#  define KB_LEFT		65361
#  define KB_RIGHT		65363
#  define KB_N			110
#  define KB_M			44
#  define KB_J			106
#  define KB_K			107
#  define KB_I			105
#  define KB_U			117
#  define KP_4			65430
#  define KP_3			65435
#  define KP_2			65433
#  define KP_1			65436
#  define KB_TAB		65289
#  define KP_PLUS		65451
#  define KP_MINUS		65453

int		deal_key(int key, t_general *info);

#endif
