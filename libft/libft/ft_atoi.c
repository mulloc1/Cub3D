/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:21:38 by jaebae            #+#    #+#             */
/*   Updated: 2021/12/07 11:02:56 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_space_ch(const char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

char	ft_sign_ch(size_t *index, char chr)
{
	if (chr == '+')
	{
		(*index)++;
		return (1);
	}
	else if (chr == '-')
	{
		(*index)++;
		return (-1);
	}
	return (1);
}

int	ft_is_overflow(long num, long add)
{
	if (num > LONG_MAX / 10)
		return (1);
	if (add > LONG_MAX - (num * 10))
		return (1);
	return (0);
}

int	ft_is_underflow(long num, long add)
{
	if (num > LONG_MAX / 10)
		return (1);
	if (add > (LONG_MAX - (num * 10) + 1) && num != 0)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	cnt;
	char	sign;
	long	result;

	i = ft_space_ch(str);
	sign = ft_sign_ch(&i, str[i]);
	cnt = 0;
	result = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (ft_is_overflow(result, str[i] - '0') && sign > 0)
			error_handler("Error", 1);
		else if (ft_is_underflow(result, str[i] - '0') && sign < 0)
			error_handler("Error", 1);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return ((int)(result * sign));
}
