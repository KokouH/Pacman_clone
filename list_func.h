/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:10:51 by lwanita           #+#    #+#             */
/*   Updated: 2022/01/12 18:10:54 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_FUNC_H
# define LIST_FUNC_H
# include "head.h"

t_list	*create_list(char *str);
void	add_back(t_list *lst, char *str);
int		lst_size(t_list *lst);
int		check_lst(t_list *lst);

#endif
