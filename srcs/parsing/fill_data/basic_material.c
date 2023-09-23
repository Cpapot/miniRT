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
