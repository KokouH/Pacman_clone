/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:11:14 by lwanita           #+#    #+#             */
/*   Updated: 2022/01/12 18:11:15 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "list_func.h"
#include "head.h"
#include "mlx/mlx.h"

void	intm_init(t_vars *vars)
{
	int		i;
	int		len;
	t_list	*tmp;

	tmp = vars->lst;
	vars->intm = (int **)malloc(sizeof(int *) * vars->height);
	i = 0;
	len = vars->height;
	while (i < len)
	{
		vars->intm[i] = vars->lst->intm;
		vars->lst = vars->lst->next;
		i++;
	}
	vars->lst = tmp;
}

int	eat_count(t_vars *vars)
{
	int	ret;
	int	x;
	int	y;

	ret = 0;
	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->intm[y][x] == -3)
				ret++;
			x++;
		}
		y++;
	}
	return (ret);
}

void	eat_init(t_vars *vars)
{
	int	i;
	int	x;
	int	y;

	vars->eat_c = eat_count(vars);
	vars->eat_map = malloc(sizeof(t_eatm) * vars->eat_c);
	y = 0;
	i = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->intm[y][x] == -3)
			{
				vars->eat_map[i].x = x;
				vars->eat_map[i].y = y;
				vars->eat_map[i].b = 1;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	free_lst(t_vars	*vars)
{
	t_list	*tmp;

	tmp = vars->lst;
	while (tmp)
	{
		free(tmp->str);
		tmp = tmp->next;
	}
}
