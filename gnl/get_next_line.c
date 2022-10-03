/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:48:00 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/29 17:50:55 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10

char	*str25(char *s)
{
	if (!s)
	{
		s = malloc(1);
		s[0] = '\0';
	}
	return (s);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*ret;
	static char	*stat;
	int			re;

	if (fd < 0 || fd > 256 || BUFFER_SIZE < 1)
		return (NULL);
	re = 1;
	stat = str25(stat);
	while (re && !(ft_strchr(stat, '\n')))
	{
		re = read(fd, buff, BUFFER_SIZE);
		if (re == -1)
		{
			free(stat);
			return (NULL);
		}
		buff[re] = '\0';
		stat = ft_strjoin(stat, buff);
	}
	ret = ft_strdup(stat);
	stat = ft_update(stat);
	return (ret);
}
