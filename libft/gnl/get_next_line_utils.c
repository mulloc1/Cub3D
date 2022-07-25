/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baejaemin <baejaemin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:14:59 by jaebae            #+#    #+#             */
/*   Updated: 2022/03/02 14:00:41 by baejaemin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen_nl(src);
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	i = -1;
	if (src < dst)
	{
		while (n > 0)
		{
			((unsigned char *)dst)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
		while (++i < n)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen_nl(s);
	while (i <= s_len)
	{
		if (s[i] == (signed char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	result = (void *)malloc(count * size);
	if (result == NULL)
		return (NULL);
	i = -1;
	while (++i < count * size)
		((unsigned char *)result)[i] = 0;
	return (result);
}

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((unsigned char *)b)[i] = (unsigned char)c;
	return (b);
}
