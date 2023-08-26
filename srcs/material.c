/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:49:36 by cpapot            #+#    #+#             */
/*   Updated: 2023/08/01 23:06:26 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_material	metal_material(void)
{
	t_material	metal;

	metal.specular_coef = 0.64;
	metal.alpha = 15;
	metal.reflection = 0.25;
	return (metal);
}
