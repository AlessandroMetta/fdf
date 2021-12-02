CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT = libft/libft.a
LIBMLX = mlx/libmlx.dylib

NAME = fdf

SRCS =	srcs/main.c		\
	srcs/parse.c	\
	srcs/parse_utils.c	\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
			make -C ./libft
			make -C ./mlx
			$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(LIBMLX) $(OBJS)

all : $(NAME)

clean:
	make clean -C ./libft
	make clean -C ./mlx
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
