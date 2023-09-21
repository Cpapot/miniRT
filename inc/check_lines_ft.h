#ifndef CHECK_LINES_FT
# define CHECK_LINES_FT

# include "structure.h"

typedef bool (*t_parse_ft)(t_data *data_pt, char *line);

bool manage_a(t_data *data_pt, char *line);
bool manage_c(t_data *data_pt, char *line);
bool manage_l(t_data *data_pt, char *line);
bool manage_sp(t_data *data_pt, char *line);
bool manage_pl(t_data *data_pt, char *line);
bool manage_cy(t_data *data_pt, char *line);
bool manage_di(t_data *data_pt, char *line);
bool manage_co(t_data *data_pt, char *line);
bool emmit_err(t_data *data_pt, char *line);

#endif
