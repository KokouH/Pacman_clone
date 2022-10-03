/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:47:37 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/20 15:25:26 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ds;
	size_t	ss;
	size_t	i;

	ds = ft_strlen(dst);
	ss = ft_strlen(src);
	if (dstsize <= ds)
		return (dstsize + ss);
	i = ft_strlcpy(&dst[ds], src, dstsize - ds);
	if (i == ss)
		return (ds + ss);
	return (0);
}
