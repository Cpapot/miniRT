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

bool	get_line_data_a(char *line, t_ambient_light *light_pt);
bool	get_line_data_c(char *line, t_camera *camera);
bool	get_line_data_l(char *line, t_light *light);
bool	get_line_data_sp(char *line, t_sphere *sphere);
bool	get_line_data_pl(char *line, t_plane *plane);
bool	get_line_data_cy(char *line, t_cylinder *cylinder);
bool	get_line_data_co(char *line, t_cone *cone);
bool	get_line_data_di(char *line, t_disk *disk);

#endif
