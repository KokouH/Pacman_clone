/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:53:55 by lwanita           #+#    #+#             */
/*   Updated: 2021/10/04 19:15:04 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
typedef unsigned long int	t_size_t;

void	ft_bzero(void *s, t_size_t n)
{
	char		*ch;
	t_size_t	i;

	ch = (char *)s;
	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			ch[i] = 0;
			i++;
		}
	}
}