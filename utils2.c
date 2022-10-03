/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:11:41 by lwanita           #+#    #+#             */
/*   Updated: 2022/01/12 18:11:43 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "list_func.h"
#include "head.h"
#include "mlx/mlx.h"

int	getcountentity(t_vars *vars)
{
	int	ret;
	int	x;
	int	y;

	y = 0;
	ret = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->intm[y][x] == -5
				|| vars->intm[y][x] == -4)
			{
				ret++;
			}
			x++;
		}
		y++;
	}
	return (ret);
}

void	create_entity(t_vars *vars, int ind, int type)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->intm[y][x] == type)
			{
				vars->entity[ind].x = x;
				vars->entity[ind].y = y;
				vars->entity[ind].look = 0;
				vars->entity[ind].type = type;
				vars->intm[y][x] = -1;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	entity_init(t_vars *vars)
{
	int	i;
	int	countentity;

	countentity = getcountentity(vars);
	vars->entity_c = countentity;
	vars->entity = malloc(sizeof(t_entity) * countentity);
	create_entity(vars, 0, -5);
	i = 1;
	while (i < countentity)
	{
		create_entity(vars, i, -4);
		i++;
	}
}
