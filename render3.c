/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:11:35 by lwanita           #+#    #+#             */
/*   Updated: 2022/01/12 18:11:35 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "list_func.h"
#include "render.h"
#include "mlx/mlx.h"

int	not_enemy(t_vars *vars, int x, int y)
{
	int	i;

	i = 1;
	while (i < vars->entity_c)
	{
		if (vars->entity[i].x == x && vars->entity[i].y == y)
			return (0);
		i++;
	}
	return (1);
}

void	look_up(t_vars *vars, int i)
{
	if ((vars->entity[i].look == 0)
		&& (vars->intm[vars->entity[i].y][vars->entity[i].x + 1] != -2)
		&& (not_enemy(vars, vars->entity[i].x + 1, vars->entity[i].y)))
		vars->entity[i].x++;
	if ((vars->entity[i].look == 2)
		&& (vars->intm[vars->entity[i].y][vars->entity[i].x - 1] != -2)
		&& (not_enemy(vars, vars->entity[i].x - 1, vars->entity[i].y)))
		vars->entity[i].x--;
	if ((vars->entity[i].look == 1)
		&& (vars->intm[vars->entity[i].y + 1][vars->entity[i].x] != -2)
		&& (not_enemy(vars, vars->entity[i].x, vars->entity[i].y + 1)))
		vars->entity[i].y++;
	if ((vars->entity[i].look == 3)
		&& (vars->intm[vars->entity[i].y - 1][vars->entity[i].x] != -2)
		&& (not_enemy(vars, vars->entity[i].x, vars->entity[i].y - 1)))
		vars->entity[i].y--;
}

void	medium_brain(t_vars *vars, int i)
{
	int	pr;

	pr = -1;
	if ((vars->entity[0].x > vars->entity[i].x)
		&& (vars->intm[vars->entity[i].y][vars->entity[i].x + 1] != -2))
		pr = 0;
	if ((vars->entity[0].x < vars->entity[i].x)
		&& (vars->intm[vars->entity[i].y][vars->entity[i].x - 1] != -2))
		pr = 2;
	if ((vars->entity[0].y > vars->entity[i].y)
		&& (vars->intm[vars->entity[i].y + 1][vars->entity[i].x] != -2))
		pr = 1;
	if ((vars->entity[0].y < vars->entity[i].y)
		&& (vars->intm[vars->entity[i].y - 1][vars->entity[i].x] != -2))
		pr = 3;
	if (pr == -1)
		pr = 0;
	vars->entity[i].look = pr;
	look_up(vars, i);
}

void	ai_steps(t_vars *vars)
{
	int	i;

	i = 1;
	while (i < vars->entity_c)
	{
		medium_brain(vars, i);
		i++;
	}
}

void	update_cor(t_vars *vars)
{
	look_up(vars, 0);
	ai_steps(vars);
}
