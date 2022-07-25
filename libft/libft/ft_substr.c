/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:20:43 by jaebae            #+#    #+#             */
/*   Updated: 2021/12/02 11:56:50 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	i = 0;
	while (i < len && s[start + i])
		i++;
	result = ft_calloc(i + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (++i < len && s[start + i])
		result[i] = s[start + i];
	return (result);
}
