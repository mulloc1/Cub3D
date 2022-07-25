/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:54:06 by jaebae            #+#    #+#             */
/*   Updated: 2021/11/30 12:05:24 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;

	i = -1;
	s_len = ft_strlen(s);
	while (++i <= s_len)
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	return (NULL);
}
