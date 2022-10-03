/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:36:29 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/30 17:38:08 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"
#include <stddef.h>
#include <unistd.h>

int	f_csi(va_list va, char arg)
{
	int		ret;
	int		c;
	char	*aa;

	ret = 0;
	if (arg == 'c')
	{
		c = va_arg(va, int);
		write(1, &c, 1);
		ret++;
	}
	if (arg == 's')
	{
		aa = va_arg(va, char *);
		ret += ft_putstr_fd(aa, 1);
	}
	if (arg == '%')
	{
		write(1, "%", 1);
		ret++;
	}
	return (ret);
}

int	f_puxX(va_list va, char arg)
{
	int				ret;
	void			*aa;
	unsigned int	asd;
	unsigned long	dsa;

	ret = 0;
	if (arg == 'p')
	{
		ft_putstr_fd("0x", 1);
		aa = va_arg(va, void *);
		ret += ft_putpoint((size_t)aa) + 2;
	}
	if (arg == 'u')
	{
		asd = va_arg(va, unsigned int);
		ret += ft_putunsign(asd);
	}
	if (arg == 'X')
	{
		dsa = va_arg(va, unsigned long);
		ret += ft_putheX(dsa);
	}
	return (ret);
}

int	xu_(va_list va, char arg)
{
	int				ret;
	int				c;
	unsigned long	dsa;

	ret = 0;
	if (arg == 'i' || arg == 'd')
	{
		c = va_arg(va, int);
		ret += ft_putnbr_fd(c, 1);
	}
	if (arg == 'x')
	{
		dsa = va_arg(va, unsigned long);
		ret += ft_puthex(dsa);
	}
	return (ret);
}
