/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:43:11 by jaebae            #+#    #+#             */
/*   Updated: 2022/08/01 14:43:42 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(int cmp, char *message)
{
	if (cmp)
	{
		write(1, message, ft_strlen(message));
		exit(1);
	}		
}

void	ft_str_array_free(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

int	ft_valid_filename(char *file)
{
	unsigned int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".cub", 5))
		return (0);
	return (1);
}
