#ifndef GET_LINES_FT_H
# define GET_LINES_FT_H

# include "structure.h"

bool    ft_material_on(char *line, t_material *dst);
double to_decimal_ll(long long nb, char *line);
bool	ft_atoratio_on(char *line, double *dst);
bool	ft_atofov_on(char *line, double *dst);
bool	ft_atovec_on(char *line, t_vec_3 *dst);
bool	ft_atocoord_on(char *line, t_point *dst);
void	go_to_next_float(char **line);
bool	ft_atorgb_on(char *line, t_color *dst);
void	go_to_next_rgb(char **line);
void	go_to_next_data(char **line_pt);
bool	ft_atod_on(char *line, double *dst);
bool	ft_atof_on(char *line, double *dst);

#endif
