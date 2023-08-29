#ifndef CHECK_LINES_FT
# define CHECK_LINES_FT

# include "structure.h"

typedef bool (*t_parse_ft)(t_minirt_data *data_pt, char *line);

bool manage_a(t_minirt_data *data_pt, char *line);
bool manage_c(t_minirt_data *data_pt, char *line);
bool manage_l(t_minirt_data *data_pt, char *line);
bool manage_sp(t_minirt_data *data_pt, char *line);
bool manage_pl(t_minirt_data *data_pt, char *line);
bool manage_cy(t_minirt_data *data_pt, char *line);
bool manage_di(t_minirt_data *data_pt, char *line);
bool manage_co(t_minirt_data *data_pt, char *line);
bool emmit_err(t_minirt_data *data_pt, char *line);

#endif
