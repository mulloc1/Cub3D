/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baejaemin <baejaemin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:26:58 by jaebae            #+#    #+#             */
/*   Updated: 2022/03/02 14:00:27 by baejaemin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# define FD_MAX 256 
# define BUFFER_SIZE 4096

char	*get_next_line(int fd);
char	*get_next_line2(int fd, char **buf);
size_t	ft_strlen_nl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
char	*ft_str_create(char *buf, char *str);
void	*ft_memset(void *b, int c, size_t n);

#endif
