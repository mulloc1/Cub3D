/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:19:07 by jaebae            #+#    #+#             */
/*   Updated: 2021/11/30 12:41:24 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (result == NULL)
		return (NULL);
	temp = result;
	lst = lst->next;
	while (lst != NULL)
	{	
		temp->next = ft_lstnew(f(lst->content));
		if (temp->next == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (result);
}
