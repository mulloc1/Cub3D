/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:46:34 by jaebae            #+#    #+#             */
/*   Updated: 2021/11/30 12:04:17 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (((unsigned const char *)s1)[i] != ((unsigned const char *)s2)[i])
			return (((unsigned const char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}
