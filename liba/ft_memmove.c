/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:09:19 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/12 18:09:37 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dest, void *source, size_t len)
{
	size_t	i;

	if ((char *)dest < (char *)source)
	{
		i = 0;
		while (i < len)
		{
			((char *)dest)[i] = ((char *)source)[i];
			i++;
		}
	}
	else if ((char *)dest > (char *)source)
	{
		while (len-- > 0)
			((char *)dest)[len] = ((char *)source)[len];
	}
	return (dest);
}
