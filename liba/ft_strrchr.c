/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:48:41 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/20 15:25:42 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ss;

	ss = (char *)s + ft_strlen(s);
	while (*ss != (char)c)
	{
		if (ss == s)
			return (NULL);
		ss--;
	}
	return (ss);
}
