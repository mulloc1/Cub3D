/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_all_arg_free.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:38:54 by jaebae            #+#    #+#             */
/*   Updated: 2022/03/08 15:38:56 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_all_arg_free(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = -1;
	while (s2[++j])
		result[i + j] = s2[j];
	free((void *)s1);
	free((void *)s2);
	return (result);
}
