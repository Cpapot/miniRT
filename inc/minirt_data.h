//
// Created by bpoumeau on 6/13/23.
//

#ifndef MINIRT_DATA_H
# define MINIRT_DATA_H

# include "structure.h"
# include "stdbool.h"

void	free_minirt_data_content(t_minirt_data *data_pt);
bool	allocate_data(t_minirt_data *data_pt);

#endif
