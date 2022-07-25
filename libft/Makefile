# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baejaemin <baejaemin@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 20:54:36 by jaebae            #+#    #+#              #
#    Updated: 2022/03/23 15:46:55 by jaebae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

AR = ar
ARFLAGS = crs

SRCS = \
libft/ft_substr.c \
libft/ft_split.c \
libft/ft_itoa.c \
libft/ft_atoi.c \
libft/ft_atof.c \
libft/ft_bzero.c \
libft/ft_calloc.c \
libft/ft_memset.c \
libft/ft_memcpy.c \
libft/ft_memmove.c \
libft/ft_memchr.c \
libft/ft_memcmp.c \
libft/ft_strlen.c \
libft/ft_isalpha.c \
libft/ft_isdigit.c \
libft/ft_isalnum.c \
libft/ft_isascii.c \
libft/ft_isprint.c \
libft/ft_isspace.c \
libft/ft_toupper.c \
libft/ft_tolower.c \
libft/ft_strchr.c \
libft/ft_strrchr.c \
libft/ft_strncmp.c \
libft/ft_strlcpy.c \
libft/ft_strlcat.c \
libft/ft_strnstr.c \
libft/ft_strdup.c \
libft/ft_strjoin.c \
libft/ft_strjoin_all_arg_free.c \
libft/ft_strjoin_first_arg_free.c \
libft/ft_strjoin_second_arg_free.c \
libft/ft_strtrim.c \
libft/ft_strmapi.c \
libft/ft_putchar_fd.c \
libft/ft_putstr_fd.c \
libft/ft_putendl_fd.c \
libft/ft_putnbr_fd.c \
libft/ft_striteri.c \
libft/error_handler.c \
ft_printf/ft_convert.c \
ft_printf/ft_convert2.c \
ft_printf/ft_printf.c \
ft_printf/ft_printf_utils.c \
libft/ft_lstadd_back.c \
libft/ft_lstadd_front.c \
libft/ft_lstclear.c \
libft/ft_lstdelone.c \
libft/ft_lstiter.c \
libft/ft_lstlast.c \
libft/ft_lstmap.c \
libft/ft_lstnew.c \
libft/ft_lstsize.c \
libft/ft_2d_array_free.c \
gnl/get_next_line.c \
gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

fclean : clean
	rm -f $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	rm -f $(OBJS)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : re fclean clean bonus all
