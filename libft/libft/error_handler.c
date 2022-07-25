/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:15:34 by jaebae            #+#    #+#             */
/*   Updated: 2022/03/28 14:15:35 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_handler(char *message, int code)
{
	perror(message);
	exit(code);
}
