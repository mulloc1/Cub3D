/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:07:46 by jaebae            #+#    #+#             */
/*   Updated: 2021/11/23 19:50:34 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dest_len >= dstsize)
		return (src_len + dstsize);
	else
	{
		i = -1;
		while (src[++i] && dest_len + i < dstsize - 1)
			dst[dest_len + i] = src[i];
		dst[dest_len + i] = '\0';
		return (src_len + dest_len);
	}
}
