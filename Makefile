CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

# libraries
MLX = libmlx.dylib
LIBFT = libft/libft.a

NAME = fdf

SRCS =	srcs/fdf_main.c		\
	srcs/fdf_realloc_map.c	\
	srcs/fdf_utils.c	\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
			make -C ./libft
			make -C ./mlx
			mv mlx/$(MLX) .
			$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(LIBFT) $(MLX) $(OBJS)

all : $(NAME)

clean:
	make clean -C ./libft
	make clean -C ./mlx
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft
	rm libmlx.dylib

re: fclean all

.PHONY: all clean fclean re
