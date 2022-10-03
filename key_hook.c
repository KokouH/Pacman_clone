/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:11:51 by lwanita           #+#    #+#             */
/*   Updated: 2022/01/12 18:11:52 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "mlx/mlx.h"
#include "keys.h"
#include <stdlib.h>

int	key_hook(int key, t_vars *vars)
{
	int	i;

	if (key == KEY_A)
		vars->entity[0].look = 2;
	if (key == KEY_W)
		vars->entity[0].look = 3;
	if (key == KEY_S)
		vars->entity[0].look = 1;
	if (key == KEY_D)
		vars->entity[0].look = 0;
	i = vars->width;
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlxw);
		exit(0);
	}
	return (0);
}
