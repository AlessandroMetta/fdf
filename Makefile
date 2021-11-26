CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
# MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

# libraries
MLX = libmlx.a
LIBFT = libft/libft.a

NAME = fdf

SRCS =	srcs/fdf_main.c		\
	srcs/fdf_parse_map.c	\
	srcs/fdf_utils.c	\
#	srcs/fdf_realloc_map.c	\
#	srcs/fdf_draw.c	\
#	srcs/fdf_mlx_handling.c	\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
			make -C ./libft
			# make -C ./mlx
			# mv mlx/$(MLX) .
			$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJS)

all : $(NAME)

clean:
	make clean -C ./libft
	# make clean -C ./mlx
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft
	# rm $(MLX)

re: fclean all

.PHONY: all clean fclean re
