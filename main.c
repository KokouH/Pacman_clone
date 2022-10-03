/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:11:23 by lwanita           #+#    #+#             */
/*   Updated: 2022/01/12 18:11:24 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"
#include "head.h"
#include "render.h"
#include "list_func.h"
#include "mlx/mlx.h"

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	castom_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlxw);
	exit(0);
}

void	do_vars(t_vars *vars)
{
	vars->game_stat = 0;
	vars->mlx = mlx_init();
	vars->height = lst_size(vars->lst);
	vars->width = ft_strlen(vars->lst->str);
	images_init(vars);
	intm_init(vars);
	eat_init(vars);
	entity_init(vars);
	free_lst(vars);
	vars->mlxw = mlx_new_window(vars->mlx, 30 * vars->width,
			30 * vars->height, "Pacman");
	mlx_loop_hook(vars->mlx, &render_func, vars);
	mlx_hook(vars->mlxw, 2, 0, key_hook, vars);
	mlx_hook(vars->mlxw, 17, 0, castom_exit, vars);
	mlx_loop(vars->mlx);
}

void	lines25(t_vars *vars, int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	vars->lst = create_list(tmp);
	while (tmp)
	{
		tmp = get_next_line(fd);
		if (tmp)
			add_back(vars->lst, tmp);
	}
	if (!check_lst(vars->lst))
	{
		ft_printf("Map error");
		exit(2);
	}
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (argc != 2)
	{
		ft_printf("Error");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	lines25(vars, fd);
	do_vars(vars);
	return (0);
}
