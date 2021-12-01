CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
AR = ar rc
RM = rm -rf

SRCS = ft_strlen.c \
	   ft_putstr.c \
	   get_next_line.c \
	   ft_strdup.c \
	   ft_strchr.c \
	   ft_putendl.c \
	   ft_strjoin.c \
	   ft_atoi_base.c \
	   ft_split.c \
	   ft_putnbr_fd.c	\
	   ft_memmove.c \

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
