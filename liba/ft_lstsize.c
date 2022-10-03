/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:51:18 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/20 15:22:48 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_lstsize(t_list *lst)
{
	t_list	*list;
	int		ret;

	ret = 0;
	list = lst;
	while (list)
	{
		list = list -> next;
		ret++;
	}
	return (ret);
}
