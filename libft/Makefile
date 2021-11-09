CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libft.a
AR = ar rc
RM = rm -rf

SRCS = ft_strlen.c \
	   ft_putstr.c \
	   get_next_line.c \
	   ft_memmove.c \
	   ft_bzero.c \
	   ft_realloc.c \
	   ft_strdup \
	   ft_strchr.c \

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			ranlib $(NAME)

all: 		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
