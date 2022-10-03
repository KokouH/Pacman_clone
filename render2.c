/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:11:06 by lwanita           #+#    #+#             */
/*   Updated: 2022/01/12 18:11:07 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "render.h"
#include "list_func.h"
#include "mlx/mlx.h"
#include "liba/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>

void	update_stat(t_vars *vars)
{
	int	i;

	i = 1;
	while (i < 3)
	{
		if (vars->entity[0].x == vars->entity[i].x
			&& vars->entity[0].y == vars->entity[i].y)
			vars->game_stat = 1;
		i++;
	}
}

void	out_eat(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlxw,
		vars->images[0]->image, 30 * x, 30 * y);
}

void	image_eat(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->eat_c)
	{
		if (vars->entity[0].x == vars->eat_map[i].x
			&& vars->entity[0].y == vars->eat_map[i].y)
			vars->eat_map[i].b = 0;
		if (vars->eat_map[i].b)
			out_eat(vars, vars->eat_map[i].x, vars->eat_map[i].y);
		i++;
	}
}

void	render_func2(t_vars *vars)
{
	if (vars->game_stat == 1)
	{
		mlx_string_put(vars->mlx, vars->mlxw, 100, 100, 16744456, "End game");
		mlx_string_put(vars->mlx, vars->mlxw, 100, 150, 16744456, "You lose!");
		mlx_string_put(vars->mlx, vars->mlxw, 100, 200, 16744456, "HA HA HA!");
	}
	else if (vars->game_stat == 2)
	{
		mlx_string_put(vars->mlx, vars->mlxw, 100, 100, 16744456, "You won!");
		mlx_string_put(vars->mlx, vars->mlxw, 100, 150, 16744456, "try again");
	}
}

int	render_func(t_vars *vars)
{
	static int	frame;
	static int	step;

	mlx_clear_window(vars->mlx, vars->mlxw);
	if (vars->game_stat == 0)
	{
		image_static(vars, step);
		image_eat(vars);
		image_entity(vars, frame);
	}
	else
		render_func2(vars);
	update_stat(vars);
	if (frame == 20 && vars->game_stat == 0)
	{
		update_cor(vars);
		ft_printf("Step: %i\n", step);
		step++;
		frame = 0;
	}
	frame++;
	return (0);
}
