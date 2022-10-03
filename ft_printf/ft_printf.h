/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwanita <lwanita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:13:21 by lwanita           #+#    #+#             */
/*   Updated: 2021/11/08 17:33:45 by lwanita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
int	f_csi(va_list va, char c);
int	f_puxX(va_list va, char c);
int	ft_putpoint(size_t a);
int	ft_putunsign(unsigned int a);
int	ft_puthex(unsigned int a);
int	ft_putheX(unsigned int a);
int	xu_(va_list va, char arg);
int	ft_printf(const char *arg, ...);

#endif
