/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:42:32 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/27 14:42:37 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"

t_lstc	*read_lstc_from_fd(int fd);
void	ft_lstclean(t_lstc *head, void (*del)(void *));
void	lstc_cpy_in_str(t_lstc	*lst, char **str);
t_lstc	*lstc_clear(t_lstc *trash);

char *ft_strdup_no(char *str)
{
	char *dst;
	char *tmp;

	dst = malloc(ft_strlen(str) + 1);
	tmp = dst;
	while (*str)
	{
		*tmp = *str;
		tmp++;
		str++;
	}
	return (dst);
}

size_t	lstc_size(t_lstc *lst)
{
	size_t	ret_val;

	ret_val = 0;
	while (lst)
	{
		lst = lst->next;
		ret_val++;
	}
	return (ret_val);
}

bool	read_fd_in_str(int fd, char **dst)
{
	t_lstc	*lst;

	lst = read_lstc_from_fd(fd);
	if (lst == NULL)
	{
		*dst = ft_strdup_no("");
		if (errno)
			return (false);
		return (true);
	}
	*dst = malloc(lstc_size(lst) + 1);
	if ((*dst) == NULL)
		return (lstc_clear(lst), false);
    lstc_cpy_in_str(lst, dst);
	lstc_clear(lst);
	return (true);
}
