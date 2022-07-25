#include "../libft/libft.h"

size_t	ft_putstr_fd_n(char *s, int fd)
{
	size_t	i;

	if (s == NULL || fd < 0)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		write(fd, &s[i], 1);
	return (i);
}

size_t	ft_putchar_fd_n(char c, int fd)
{
	return (write(fd, &c, 1));
}
