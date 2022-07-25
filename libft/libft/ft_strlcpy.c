/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:06:13 by jaebae            #+#    #+#             */
/*   Updated: 2021/12/02 15:14:33 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = -1;
	if (dstsize != 0)
	{
		while (++i < dstsize - 1 && src[i])
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
