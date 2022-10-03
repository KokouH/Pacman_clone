/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:42:52 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/20 15:19:45 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	get_ret(const char *s, int i)
{
	int	ret;

	ret = 0;
	while (ft_isdigit(s[i]) != 0)
	{
		ret = ret * 10 + s[i] - '0';
		i++;
	}
	return (ret);
}

int	ft_atoi(const char *s)
{
	unsigned long	ret;
	int				i;

	while (s && (*s == ' ' || *s == '\t' || *s == '\n'
			|| *s == '\v' || *s == '\f' || *s == '\r'))
		s++;
	if (s[0] == '-')
		i = 1;
	else
		i = 0;
	if (*s == '+')
		s++;
	ret = get_ret(s, i);
	if (ret > 2147483648)
	{
		if (s[0] == '-')
			return (0);
		else
			return (-1);
	}
	if (s[0] == '-')
		return (-(int)ret);
	else
		return ((int)ret);
}
