/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:02:00 by jaebae            #+#    #+#             */
/*   Updated: 2021/12/07 11:04:03 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digit_count(int n)
{
	size_t	digit_cnt;
	long	temp;

	digit_cnt = 0;
	temp = n;
	if (temp < 0)
	{
		digit_cnt++;
		temp *= -1;
	}
	while (temp > 0)
	{
		temp /= 10;
		digit_cnt++;
	}	
	return (digit_cnt);
}

char	*ft_itoa(int n)
{
	size_t	digit_cnt;
	long	temp;
	char	*result;

	if (n == 0)
		digit_cnt = 1;
	else
		digit_cnt = ft_digit_count(n);
	result = ft_calloc(digit_cnt + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	temp = n;
	if (temp == 0)
		result[0] = 0 + 48;
	if (temp < 0)
	{
		result[0] = '-';
		temp *= -1;
	}
	while (temp > 0)
	{
		result[--digit_cnt] = temp % 10 + 48;
		temp /= 10;
	}
	return (result);
}
