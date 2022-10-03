/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:11:57 by lwanita           #+#    #+#             */
/*   Updated: 2022/01/12 18:11:58 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(char *str);

static int	*str2int(char *str)
{
	size_t	i;
	int		*ret;

	ret = malloc(sizeof(int) * ft_strlen(str));
	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			ret[i] = -1;
		else if (str[i] == '1')
			ret[i] = -2;
		else if (str[i] == 'C')
			ret[i] = -3;
		else if (str[i] == 'e')
			ret[i] = -4;
		else if (str[i] == 'P')
			ret[i] = -5;
		else if (str[i] == 'E')
			ret[i] = -6;
		else
			return (NULL);
		i++;
	}
	return (ret);
}

t_list	*create_list(char *str)
{
	t_list	*ret;
	int		*tmp;

	ret = malloc(sizeof(t_list));
	ret->str = str;
	tmp = str2int(str);
	if (!tmp)
	{
		free(ret);
		return (NULL);
	}
	ret->intm = tmp;
	ret->next = NULL;
	return (ret);
}

void	add_back(t_list *lst, char *str)
{
	while (lst->next)
		lst = lst->next;
	lst->next = create_list(str);
}

int	check_lst(t_list *lst)
{
	int		i;
	size_t	slen;

	slen = ft_strlen(lst->str);
	i = 0;
	while (lst->str[i])
		if (lst->str[i++] != '1')
			return (0);
	while (lst->next)
	{
		lst = lst->next;
		if (ft_strlen(lst->str) != slen)
			return (0);
		if (lst->str[0] != '1' || lst->str[slen - 1] != '1')
			return (0);
	}
	i = 0;
	while (lst->str[i])
		if (lst->str[i++] != '1')
			return (0);
	if (ft_strlen(lst->str) != slen)
		return (0);
	return (1);
}

int	lst_size(t_list *lst)
{
	int	ret;

	ret = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		ret++;
	}
	return (ret);
}
