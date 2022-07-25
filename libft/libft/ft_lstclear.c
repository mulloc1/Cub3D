/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:07:52 by jaebae            #+#    #+#             */
/*   Updated: 2021/12/02 13:42:48 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (*lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		if (temp->content != NULL)
			del(temp->content);
		*lst = temp->next;
		free(temp);
	}
}
