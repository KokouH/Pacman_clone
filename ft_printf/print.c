/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:38:07 by lwanita           #+#    #+#             */
/*   Updated: 2021/11/08 17:51:11 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include "libft.h"
#include "ft_printf.h"

int	ft_putpoint(size_t s)
{
	int		ret;
	size_t	i;
	char	c;

	if (s == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 1;
	while (s / i > 15)
		i = i * 16;
	ret = 0;
	while (i > 0)
	{
		if (s / i < 10)
			c = s / i + 48;
		else
			c = s / i - 10 + 97;
		write(1, &c, 1);
		s = s % i;
		i = i / 16;
		ret++;
	}
	return (ret);
}

int	ft_putunsign(unsigned int n)
{
	int				ret;
	unsigned int	i;
	char			c;

	i = 1;
	while (n / i > 9)
		i *= 10;
	ret = 0;
	while (i > 0)
	{
		c = n / i + 48;
		write(1, &c, 1);
		n %= i;
		i /= 10;
		ret++;
	}
	return (ret);
}

int	ft_puthex(unsigned int s)
{	
	int				ret;
	unsigned long	i;
	char			c;

	if (s == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 1;
	while (s / i > 15)
		i = i * 16;
	ret = 0;
	while (i > 0)
	{
		if (s / i < 10)
			c = s / i + 48;
		else
			c = s / i - 10 + 97;
		write(1, &c, 1);
		s = s % i;
		i = i / 16;
		ret++;
	}
	return (ret);
}

int	ft_putheX(unsigned int s)
{	
	int				ret;
	unsigned long	i;
	char			c;

	if (s == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 1;
	while (s / i > 15)
		i = i * 16;
	ret = 0;
	while (i > 0)
	{
		if (s / i < 10)
			c = s / i + 48;
		else
			c = s / i - 10 + 65;
		write(1, &c, 1);
		s = s % i;
		i = i / 16;
		ret++;
	}
	return (ret);
}

int	ft_printf(const char *arg, ...)
{
	int				ret;
	va_list			va;

	va_start(va, arg);
	ret = 0;
	while (*arg)
	{
		if (*arg == '%')
		{
			arg++;
			ret += f_csi(va, *arg);
			ret += f_puxX(va, *arg);
			ret += xu_(va, *arg);
		}
		else
		{
			write(1, arg, 1);
			ret++;
		}
		arg++;
	}
	return (ret);
}
