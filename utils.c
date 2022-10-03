/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:12:11 by lwanita           #+#    #+#             */
/*   Updated: 2022/01/12 18:12:11 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "list_func.h"
#include "head.h"
#include "mlx/mlx.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static t_img	*img_init(void *mlx, char *path)
{
	t_img	*ret;

	ret = (t_img *)malloc(sizeof(t_img));
	ret->image = mlx_xpm_file_to_image(mlx, path,
			&(ret->width), &(ret->height));
	ret->image_ch = mlx_get_data_addr(ret->image, &(ret->bpp),
			&(ret->size_line), &(ret->endian));
	if (!ret->image)
		return (NULL);
	return (ret);
}

void	images_init(t_vars *vars)
{
	t_img	**ret;

	ret = (t_img **)malloc(sizeof(t_img *) * 16);
	ret[0] = img_init(vars->mlx, "img/eat.xpm");
	ret[1] = img_init(vars->mlx, "img/pacman0.xpm");
	ret[2] = img_init(vars->mlx, "img/pacman1.xpm");
	ret[3] = img_init(vars->mlx, "img/pacman2.xpm");
	ret[4] = img_init(vars->mlx, "img/pacman3.xpm");
	ret[5] = img_init(vars->mlx, "img/pacman4.xpm");
	ret[6] = img_init(vars->mlx, "img/ghost11.xpm");
	ret[7] = img_init(vars->mlx, "img/ghost12.xpm");
	ret[8] = img_init(vars->mlx, "img/ghost13.xpm");
	ret[9] = img_init(vars->mlx, "img/ghost14.xpm");
	ret[10] = img_init(vars->mlx, "img/ghost15.xpm");
	ret[11] = img_init(vars->mlx, "img/ghost16.xpm");
	ret[12] = img_init(vars->mlx, "img/ghost17.xpm");
	ret[13] = img_init(vars->mlx, "img/ghost18.xpm");
	ret[14] = img_init(vars->mlx, "img/black.xpm");
	ret[15] = img_init(vars->mlx, "img/white.xpm");
	ret[16] = img_init(vars->mlx, "img/yeallow.xpm");
	vars->images = ret;
}
