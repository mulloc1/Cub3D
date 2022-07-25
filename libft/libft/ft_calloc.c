/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:55:36 by jaebae            #+#    #+#             */
/*   Updated: 2021/11/30 09:59:34 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
