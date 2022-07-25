/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:34:39 by jaebae            #+#    #+#             */
/*   Updated: 2021/11/20 18:24:48 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	s_len;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	result = ft_calloc(sizeof(char), s_len + 1);
	if (result == NULL)
		return (NULL);
	i = -1;
	while (++i < s_len)
		result[i] = (*f)(i, s[i]);
	return (result);
}
