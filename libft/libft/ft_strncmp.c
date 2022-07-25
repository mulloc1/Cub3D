/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:37:58 by jaebae            #+#    #+#             */
/*   Updated: 2021/11/30 12:03:01 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1_temp;
	const unsigned char	*s2_temp;
	size_t				i;

	if (n == 0)
		return (0);
	s1_temp = (const unsigned char *)s1;
	s2_temp = (const unsigned char *)s2;
	i = -1;
	while (s1_temp[++i] && s2_temp[i] && i < n - 1)
		if (s1_temp[i] != s2_temp[i])
			return (s1_temp[i] - s2_temp[i]);
	return (s1_temp[i] - s2_temp[i]);
}
