#include "../../../inc/structure.h"
#include "../../../libft/includes/libft.h"

double	to_decimal(int tmp, char *line);
bool	ft_atof_on(char *line, double *dst);
void	_go_to_decimal_part(char **line);

bool	ft_atofov_on(char *line, double *dst)
{
	if (ft_atof_on(line, dst) == false)
		return (false);
	if (*dst > 180 || *dst < 0)
		return (false);
	return (true);
}

double	to_decimal_ll(long long nb, char *line)
{
	double	dst;

	dst = nb;
	while (ft_isdigit(*line))
	{
		line++;
		dst /= 10;
	}
	return (dst);
}

bool	ft_atof_on(char *line, double *dst)
{
	int		integer;
	int		tmp;
	double	decimal;

	if (ft_atoi_on(line, &integer) == false)
		return (false);
	_go_to_decimal_part(&line);
	tmp = 0;
	if (ft_isdigit(*line) && ft_atoi_on(line, &tmp) == false)
		return (false);
	decimal = to_decimal(tmp, line);
	if (integer < 0)
		decimal -= integer;
	else
		decimal += integer;
	*dst = decimal;
	return (true);
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
	_go_to_decimal_part(&line);
	if (*line != ' ' && ft_atoll_on(line, &tmp) == false)
		return (false);
	if (is_neg == false)
		decimal = to_decimal_ll(tmp, line) + integer;
	else
		decimal = integer - to_decimal_ll(tmp, line);
	*dst = decimal;
	return (true);
}

double	to_decimal(int tmp, char *line)
{
	double	dst;

	dst = tmp;
	while (ft_isdigit(*line))
	{
		dst /= 10;
		line++;
	}
	return (dst);
}
