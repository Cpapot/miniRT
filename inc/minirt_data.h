/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:59:36 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/25 16:06:29 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DATA_H
# define MINIRT_DATA_H

# include "structure.h"
# include "stdbool.h"

int		clean_minirt_data(t_data *data_pt);
bool	allocate_data(t_data *data_pt);

#endif
