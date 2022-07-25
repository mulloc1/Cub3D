/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baejaemin <baejaemin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:15:15 by jaebae            #+#    #+#             */
/*   Updated: 2022/03/02 13:59:45 by baejaemin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	p(va_list op, int *num);
void	c(va_list op, int *num);
void	d(va_list op, int *num);
void	s(va_list op, int *num);
void	x_up(va_list op, int *num);
void	u(va_list op, int *num);
void	x_lo(va_list op, int *num);
void	per(va_list op, int *num);
size_t	ft_putchar_fd_n(char c, int fd);
size_t	ft_putstr_fd_n(char *s, int fd);

#endif
