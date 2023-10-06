/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:07:46 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:07:55 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/structure.h"

t_material	basic(void)
{
	const t_material	ret = {
		.reflection = 0,
		.specular_coef = 0.4,
		.alpha = 10,
		.is_board = false
	};

	return (ret);
}
