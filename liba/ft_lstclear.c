/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:50:20 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/20 15:20:25 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	int		len;
	int		i;
	t_list	*n;

	len = ft_lstsize(*lst);
	i = 0;
	while (i < len)
	{
		n = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = n;
		i++;
	}
}
