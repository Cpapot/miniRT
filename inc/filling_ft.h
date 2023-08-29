#ifndef FILLING_FT_H
# define FILLING_FT_H
# define INIT 0
# define FILLING 1
# include "structure.h"

typedef bool (*t_filling_ft)(void *data_pt, int flag);
bool fill_a(void *data_pt, int flag);
bool fill_c(void *data_pt, int flag);
bool fill_l(void *data_pt, int flag);
bool fill_pl(void *data_pt, int flag);
bool fill_sp(void *data_pt, int flag);
bool fill_cy(void *data_pt, int flag);
bool fill_co(void *data_pt, int flag);
bool fill_di(void *data_pt, int flag);
void init_filling_ft(t_minirt_data *data_pt);

#endif
