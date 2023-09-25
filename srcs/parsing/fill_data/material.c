/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:08:08 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 15:09:21 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/structure.h"

t_material	polish(void)
{
	const t_material	ret = {
		.reflection = 0.25,
		.specular_coef = 0.64,
		.alpha = 20,
		.is_board = false
	};

	return (ret);
}

t_material	metal(void)
{
	const t_material	ret = {
		.reflection = 0.15,
		.specular_coef = 0.64,
		.alpha = 20,
		.is_board = false
	};

	return (ret);
}

t_material	mirror(void)
{
	const t_material	ret = {
		.reflection = 0.95,
		.specular_coef = 0,
		.alpha = 0,
		.is_board = false
	};

	return (ret);
}

t_material	checker(void)
{
	const t_material	ret = {
		.reflection = 0,
		.specular_coef = 0,
		.alpha = 0,
		.is_board = true
	};

	return (ret);
}

t_material	plastic(void)
{
	const t_material	ret = {
		.reflection = 0.15,
		.specular_coef = 0.66,
		.alpha = 5,
		.is_board = false
	};

	return (ret);
}
