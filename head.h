/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:10:26 by lwanita           #+#    #+#             */
/*   Updated: 2022/01/12 18:10:27 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include <stddef.h>

typedef struct s_img
{
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	void	*image;
	char	*image_ch;
}	t_img;

typedef struct s_list
{
	char			*str;
	int				*intm;
	struct s_list	*next;
}	t_list;

typedef struct s_entity
{
	int	x;
	int	y;
	int	look;
	int	type;
}	t_entity;

typedef struct s_eatm
{
	int	x;
	int	y;
	int	b;
}	t_eatm;

typedef struct s_vars
{
	void		*mlx;
	void		*mlxw;
	int			width;
	int			height;
	int			**intm;
	int			entity_c;
	int			game_stat;
	int			eat_c;
	t_eatm		*eat_map;
	t_img		**images;
	t_list		*lst;
	t_entity	*entity;
}	t_vars;

size_t	ft_strlen(char *s);
void	images_init(t_vars *lst);
int		key_hook(int ket, t_vars *lst);
void	entity_init(t_vars *vars);
void	intm_init(t_vars *vars);
void	eat_init(t_vars *vars);
void	free_lst(t_vars *vars);

#endif
