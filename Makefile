CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT = libft/libft.a

NAME = fdf

SRCS =	srcs/fdf_main.c		\
	srcs/fdf_parse.c	\
	srcs/fdf_utils.c	\

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
