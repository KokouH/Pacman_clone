/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:50:37 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/20 15:20:50 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	len;
	int	i;

	len = ft_lstsize(lst);
	i = 0;
	while (i < len)
	{
		f(lst -> content);
		lst = lst -> next;
		i++;
	}
}
