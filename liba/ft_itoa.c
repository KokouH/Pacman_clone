/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:44:18 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/15 17:44:23 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

size_t	length(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	get_i(int n, char **ret)
{
	if (n < 0)
	{
		(*ret)[0] = '-';
		return (1);
	}
	else
		return (0);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = length(n);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	i = get_i(n, &ret);
	while (len-- > i)
	{
		if (n > 0)
		{
			ret[len] = '0' + n % 10;
			n /= 10;
		}
		else
		{
			ret[len] = '0' + n % 10 * (-1);
			n /= 10;
		}
	}
	return (ret);
}
