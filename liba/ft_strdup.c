/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:47:07 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/20 15:23:47 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*r;

	i = 0;
	while (s[i])
		i++;
	r = malloc(i + 1);
	if (r == NULL)
		return (NULL);
	ft_strlcpy(r, s, ft_strlen(s) + 1);
	return (r);
}
