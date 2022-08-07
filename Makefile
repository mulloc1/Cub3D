NAME = cub3D

CC = gcc

CFLAG = -Werror -Wall -Wextra -I include -g

MMS_FLAG = -L . -lmlx -I minilibx_mms_20200219 -framework OpenGl -framework Appkit

OPENGL_FLAG = -I ./minilibx_opengl_20191021

LIBFT=libft/libft.a

MMS_LIB = minilibx_mms_20200219/libmlx.dylib

OPENGL_LIB = minilibx_opengl_20191021/libmlx.a

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

test : 
	gcc -Werror -Wall -Wextra test/main.c -g -L . -lmlx -I minilibx_mms_20200219 -framework OpenGl -framework Appkit -o cub3D

$(NAME) : $(OBJS)
	@make -C libft
	$(CC) $(CFLAG) $(INCLUDE) $(MMS_FLAG) -o $@ $^ $(LIBFT)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

.PHONY : all clean fclean re test
