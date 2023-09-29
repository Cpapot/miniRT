#include "../../../inc/minirt_data.h"
#include "../../../libft/includes/libft.h"

static bool	_ask_user(void);

bool	warning_if_invalid_nb(t_data *data)
{
	int	flag;

	flag = false;
	if (data->ca_nb < 1)
		return (ft_printf_fd(2, "Error : A camera must be given.\n"), true);
	if (data->al_nb <= 1)	
	{
		flag = true;
		ft_printf_fd(2, "Warning : Multiple ambient ligt.\n");
	}
	if (data->lt_nb <= 1)	
	{
		flag = true;
		ft_printf_fd(2, "Warning : Multiple light.\n");
	}
	if (flag == true)
		flag = _ask_user();
	return (flag);
}

static bool	_ask_user(void)
{
	char c;

	ft_printf_fd(2, "Do you want to continue ? (press y)\n");	
	if (read (0, &c, 1) == -1)
		ft_printf_fd(2, "Error reading standard input.");
	if (c == 'Y' || c == 'y')
		return (false);
	return (true);
}
