/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baejaemin <baejaemin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:30:08 by jaebae            #+#    #+#             */
/*   Updated: 2022/03/02 13:59:56 by baejaemin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf[FD_MAX];
	char		*result;

	if (buf[fd] == NULL)
	{
		buf[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (buf[fd] == NULL)
			return (NULL);
	}
	result = get_next_line2(fd, &buf[fd]);
	return (result);
}

char	*get_next_line2(int fd, char **buf)
{
	char		*result;
	int			read_result;

	result = ft_calloc(1, 1);
	if (result == NULL)
		return (NULL);
	while (!ft_strchr(result, '\n'))
	{
		if (*buf[0] == '\0')
		{
			read_result = read(fd, *buf, BUFFER_SIZE);
			if (read_result == 0 && result[0] != '\0')
				return (result);
			else if (read_result < 0 || (read_result == 0 && result[0] == '\0'))
			{
				free(result);
				free(*buf);
				*buf = 0;
				return (NULL);
			}
		}
		result = ft_str_create(*buf, result);
	}
	return (result);
}

char	*ft_str_create(char *buf, char *str)
{
	size_t	line_len;
	char	*temp;
	char	*result;

	line_len = ft_strlen_nl(buf);
	temp = (char *)malloc(sizeof(char) * line_len + 1);
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, buf, line_len + 1);
	ft_memmove(buf, buf + line_len, BUFFER_SIZE - line_len);
	ft_memset(buf + BUFFER_SIZE - line_len, '\0', line_len);
	result = ft_strjoin_gnl(str, temp);
	return (result);
}

size_t	ft_strlen_nl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = ft_calloc(ft_strlen_nl(s1) + ft_strlen_nl(s2) + 1, sizeof(char));
	if (result == 0)
		return (0);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = -1;
	while (s2[++j])
		result[i + j] = s2[j];
	free(s1);
	free(s2);
	return (result);
}
