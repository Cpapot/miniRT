/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:07:46 by cpapot            #+#    #+#             */
/*   Updated: 2023/10/02 13:15:02 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/includes/libft.h"
#include "miniRT.h"

static bool	_ask_user(void);

bool	warning_if_invalid_nb(t_data *data)
{
	int	flag;

	flag = false;
	if (data->ca_nb < 1)
		return (ft_printf_fd(2, "Error : A camera must be given.\n"), true);
	if (data->ca_nb > 1)
	{
		flag = true;
		ft_printf_fd(2, "Warning : Multiple camera.\n");
	}
	if (data->al_nb != 1)
	{
		flag = true;
		ft_printf_fd(2, "Warning : Multiple or no ambient ligt.\n");
	}
	if (data->lt_nb != 1)
	{
		flag = true;
		ft_printf_fd(2, "Warning : Multiple or no light.\n");
	}
	if (flag == true)
		flag = _ask_user();
	return (flag);
}

static bool	_ask_user(void)
{
	char	c;
	int		n_read;

	c = 0;
	ft_printf_fd(2, "Do you want to continue ? (press y)\n");
	n_read = read (0, &c, 1);
	if (n_read == 0)
		ft_printf_fd(2, "Error : standard input closed.\n");
	if (n_read == -1)
		ft_printf_fd(2, "Error : reading standard input.\n");
	if (c == 'Y' || c == 'y')
		return (false);
	return (true);
}
