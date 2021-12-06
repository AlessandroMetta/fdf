CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = libft/libft.a
LIBMLX = libmlx.dylib

MLX_FLAGS = -Lmlx -framework OpenGL -framework AppKit

NAME = fdf

SRCS =	srcs/main.c		\
	srcs/parse.c	\
	srcs/parse_utils.c	\
	srcs/exit_utils.c	\
	srcs/utils.c	\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
			make -C ./libft
			make -C ./mlx
			mv mlx/$(LIBMLX) .
			$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(LIBFT) $(LIBMLX) $(OBJS)

all : $(NAME)

clean:
	make clean -C ./libft
	make clean -C ./mlx
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBMLX)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
