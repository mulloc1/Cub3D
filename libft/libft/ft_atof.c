/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:42:24 by jaebae            #+#    #+#             */
/*   Updated: 2022/03/23 15:42:25 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	check(int *i, double *sign, char c)
{
	if (c == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else
		*sign = 1;
}

double	ft_atof(const char *str)
{
	double	digit;
	double	real;
	double	sign;
	int		i;
	int		len;

	digit = 0;
	real = 0;
	i = 0;
	len = strlen(str);
	check(&i, &sign, str[i]);
	while (str[i] != '.' && str[i])
	{
		digit *= 10;
		digit += str[i++] - 48;
	}
	while (--len > i)
	{
		real *= 0.1;
		real += str[len] - 48;
	}
	return ((digit + (real * 0.1)) * sign);
}
