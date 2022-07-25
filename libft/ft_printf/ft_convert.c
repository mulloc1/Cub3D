/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baejaemin <baejaemin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:07:29 by jaebae            #+#    #+#             */
/*   Updated: 2022/03/02 13:53:28 by baejaemin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	d(va_list op, int *cnt)
{
	char	*str;
	int		num;

	num = va_arg(op, int);
	str = ft_itoa(num);
	(*cnt) += ft_putstr_fd_n(str, 1);
	free(str);
}

void	c(va_list op, int *cnt)
{
	(*cnt) += ft_putchar_fd_n(va_arg(op, int), 1);
}

void	s(va_list op, int *cnt)
{
	char	*str;

	str = va_arg(op, char *);
	if (str == NULL)
		(*cnt) += ft_putstr_fd_n("(null)", 1);
	else
		(*cnt) += ft_putstr_fd_n(str, 1);
}

void	per(va_list op, int *cnt)
{
	op++;
	(*cnt) += ft_putchar_fd_n('%', 1);
}

void	u(va_list op, int *cnt)
{
	unsigned int	num;
	size_t			i;
	char			buf[12];
	int				temp;

	temp = *cnt;
	num = va_arg(op, int);
	i = 0;
	while (num > 0)
	{
		buf[i++] = num % 10 + 48;
		num /= 10;
	}
	while (--i + 1 >= 1)
		(*cnt) += ft_putchar_fd_n(buf[i], 1);
	if (temp == *cnt)
		*cnt += write(1, "0", 1);
}
