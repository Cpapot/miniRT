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

void	read_lst(t_lstc *lst)
{
	while (lst)
	{
		lst = lst->next;
	}
}

#include "stdio.h"
bool	read_fd_in_str(int fd, char **dst)
{
	t_lstc	*lst;

	lst = read_lstc_from_fd(fd);
	read_lst(lst);
	if (lst == NULL)
	{
		puts("in NULL");
		*dst = ft_strdup_no("");
		if (errno)
			return (false);
		return (true);
	}
	*dst = malloc(lstc_size(lst) + 1);
	if (*dst)
		lstc_cpy_in_str(lst, dst);
	else
		return (puts("la"), lstc_clear(lst), 1);
	lstc_clear(lst);
	return (true);
}
