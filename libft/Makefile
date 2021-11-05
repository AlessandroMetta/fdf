CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
AR = ar rc
RM = rm -rf
SRCS = ft_putstr.c	\
	   ft_strlen.c	\

OBJS = $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
