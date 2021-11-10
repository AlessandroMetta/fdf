#include "libft.h"

void ft_putendl(const char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
}
