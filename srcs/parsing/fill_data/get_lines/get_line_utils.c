#include "../../../../inc/structure.h"
#include "../../../../libft/includes/libft.h"
#include "../../../../inc/material.h"
#include "../../../../inc/go_to.h"

double to_decimal_ll(long long nb, char *line)
{
	double dst;

	dst = nb;
	while (ft_isdigit(*line))
	{
		line++;
		dst /= 10;
	}
	return (dst);
}

bool	ft_atod_on(char *line, double *dst)
{
	long long	integer;
	long long	tmp;
	double		decimal;
	bool		is_neg;

	tmp = 0;
	if (*line == '-')
		is_neg = true;
	else
		is_neg = false;
	if (ft_atoll_on(line, &integer) == false)
		return (false);
	go_to_decimal_part(&line);
	if (*line != ' ' && ft_atoll_on(line, &tmp) == false)
		return (false);
	if (is_neg == false)
		decimal = to_decimal_ll(tmp, line) + integer;
	else
		decimal = integer - to_decimal_ll(tmp, line);
	*dst = decimal;
	return (true);
}

bool	ft_atofov_on(char *line, double *dst)
{
	if (ft_atod_on(line, dst) == false)
		return (false);
	if (*dst > 180 || *dst < 0)
		return (false);
	return (true);
}

bool	ft_atoratio_on(char *line, double *dst)
{
	if (ft_atod_on(line, dst) == false)
		return (false);
	if (*dst > 1 || *dst < 0)
		return (false);
	return (true);
}
