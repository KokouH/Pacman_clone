/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:11:29 by lwanita           #+#    #+#             */
/*   Updated: 2022/01/12 18:11:30 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "list_func.h"
#include "mlx/mlx.h"
#include "render.h"
#include "liba/libft.h"

int	eat_all(t_vars *vars)
{
	int	i;

	i = 0;
	while ((i < vars->eat_c) && (!vars->eat_map[i].b))
		i++;
	if (i == vars->eat_c)
		return (1);
	return (0);
}

void	image_pac2(t_vars *vars)
{
	if (vars->entity[0].look == 2)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlxw,
			vars->images[4]->image,
			30 * vars->entity[0].x, 30 * vars->entity[0].y);
	}
	else if (vars->entity[0].look == 3)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlxw,
			vars->images[3]->image,
			30 * vars->entity[0].x, 30 * vars->entity[0].y);
	}
}

void	image_pac(t_vars *vars, int frame)
{
	if (frame < 10)
	{
		if (vars->entity[0].look == 0)
		{
			mlx_put_image_to_window(vars->mlx, vars->mlxw,
				vars->images[2]->image,
				30 * vars->entity[0].x, 30 * vars->entity[0].y);
		}
		else if (vars->entity[0].look == 1)
		{
			mlx_put_image_to_window(vars->mlx, vars->mlxw,
				vars->images[5]->image,
				30 * vars->entity[0].x, 30 * vars->entity[0].y);
		}
		else
			image_pac2(vars);
	}
	else
		mlx_put_image_to_window(vars->mlx, vars->mlxw,
			vars->images[1]->image,
			30 * vars->entity[0].x, 30 * vars->entity[0].y);
}

void	image_entity(t_vars *vars, int frame)
{
	int	i;

	i = 1;
	image_pac(vars, frame);
	while (i < vars->entity_c)
	{
		if (vars->entity[i].type == -4)
			mlx_put_image_to_window(vars->mlx, vars->mlxw,
				vars->images[7]->image,
				30 * vars->entity[i].x, 30 * vars->entity[i].y);
		i++;
	}
}

void	image_static(t_vars *vars, int step)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->intm[y][x] == -2)
				mlx_put_image_to_window(vars->mlx, vars->mlxw,
					vars->images[15]->image, 30 * x, 30 * y);
			if (vars->intm[y][x] == -6 && eat_all(vars))
			{
				mlx_put_image_to_window(vars->mlx, vars->mlxw,
					vars->images[16]->image, 30 * x, 30 * y);
				if (vars->entity[0].x == x && vars->entity[0].y == y)
					vars->game_stat = 2;
			}
			x++;
		}
		y++;
	}
	mlx_string_put(vars->mlx, vars->mlxw, 0, 0, 0, ft_itoa(step));
}
