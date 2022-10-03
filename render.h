/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:12:03 by lwanita           #+#    #+#             */
/*   Updated: 2022/01/12 18:12:04 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "head.h"

int		render_func(t_vars *vars);
void	look_up(t_vars *vars, int i);
void	update_cor(t_vars *vars);
void	image_entity(t_vars *vars, int frame);
void	image_static(t_vars *vars, int step);
int		eat_all(t_vars *vars);
#endif
