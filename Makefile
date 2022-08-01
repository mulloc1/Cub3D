NAME = cub3D

CC = gcc

CFLAG = -Werror -Wall -Wextra -I include

MMS_FLAG = -L . -lmlx -I minilibx_mms_20200219 -framework OpenGl -framework Appkit

OPENGL_FLAG = -I ./minilibx_opengl_20191021

LIBFT=libft/libft.a

MMS_LIB = minilibx_mms_20200219/libmlx.dylib

OPENGL_LIB = minilibx_opengl_20191021/libmlx.a

DIR = srcs/

SRCS =	$(DIR)init.c \
		$(DIR)main.c \
		$(DIR)parser.c \
		$(DIR)raycasting.c \



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
