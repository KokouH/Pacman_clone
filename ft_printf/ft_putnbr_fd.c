/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:46:09 by lwanita           #+#    #+#             */
/*   Updated: 2021/11/08 17:37:24 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd);

int	get_ret(int n, int i)
{
	int	ret;
	int	c;

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

int	ft_putnbr_fd(int n, int fd)
{
	int	ret;
	int	i;

	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	i = 1;
	ret = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ret++;
	}
	while (n / i > 9)
		i *= 10;
	ret += get_ret(n, i);
	return (ret);
}
