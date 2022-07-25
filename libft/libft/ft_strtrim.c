/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:48:11 by jaebae            #+#    #+#             */
/*   Updated: 2021/12/07 11:05:10 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_forword_search(char const *s, char const *set)
{
	size_t	forword;
	size_t	j;

	forword = -1;
	while (s[++forword])
	{
		j = -1;
		while (set[++j])
			if (ft_strchr(set, s[forword]) == NULL)
				return (forword);
	}
	return (forword);
}

size_t	ft_rear_search(char const *s, char const *set)
{
	size_t	rear;
	size_t	j;

	rear = ft_strlen(s);
	while (--rear + 1 >= 1)
	{
		j = -1;
		while (set[++j])
			if (ft_strchr(set, s[rear]) == NULL)
				return (rear);
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*result;
	size_t	j;
	size_t	forword;
	size_t	rear;

	if (s == NULL || set == NULL)
		return (NULL);
	else if (*s == '\0')
		return (ft_strdup(""));
	else if (*set == '\0')
		return (ft_strdup(s));
	forword = ft_forword_search(s, set);
	rear = ft_rear_search(s, set);
	if (forword > rear)
		return (ft_strdup(""));
	result = ft_calloc(rear - forword + 2, sizeof(char));
	if (result == NULL)
		return (NULL);
	j = 0;
	while (forword <= rear)
		result[j++] = s[forword++];
	return (result);
}
