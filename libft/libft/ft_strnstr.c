/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:56:26 by jaebae            #+#    #+#             */
/*   Updated: 2021/11/30 12:57:57 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	i = -1;
	while (++i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len && haystack[i + j])
			j++;
		if (j == needle_len)
			return ((char *)&haystack[i]);
	}
	return (NULL);
}
