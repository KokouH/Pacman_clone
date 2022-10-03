/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:38:27 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/16 19:19:16 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	k;

	if (!*n)
		return ((char *)h);
	i = 0;
	while (h[i] && i < len)
	{
		if (n[0] == h[i])
		{
			k = 0;
			while (h[i + k] == n[k] && (size_t)(i + k) < len && n[k] != '\0')
				k++;
			if (n[k] == '\0')
				return ((char *)&h[i]);
		}
		i++;
	}
	return (NULL);
}
