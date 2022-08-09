# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 12:14:34 by jonkim            #+#    #+#              #
#    Updated: 2022/08/09 12:16:33 by jonkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAG = -Werror -Wall -Wextra -I include

MMS_FLAG = -L . -lmlx -I minilibx_mms_20200219 -framework OpenGl -framework Appkit

LIBFT=libft/libft.a

MMS_LIB = minilibx_mms_20200219/libmlx.dylib

DIR = srcs/

SRCS =	$(DIR)init.c \
		$(DIR)main.c \
		$(DIR)parsing.c \
		$(DIR)parsing_is_funcs.c \
		$(DIR)parsing_put_funcs.c \
		$(DIR)parsing_utils.c \
		$(DIR)raycasting_init.c \
		$(DIR)raycasting.c \
		$(DIR)key_hook.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	@make -C libft clean
	rm -f $(OBJS)

fclean : clean
	@rm -rf libft/libft.a
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	@make -C libft
	$(CC) $(CFLAG) $(INCLUDE) $(MMS_FLAG) -o $@ $^ $(LIBFT)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

.PHONY : all clean fclean re
