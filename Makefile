# compiling specs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

# libraries
MLX = libmlx.dylib
LIBFT = libft/libft.a

NAME = fdf

SRCS = srcs/fdf_main.c \

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJS)

all : $(NAME)

clean:
	make clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
