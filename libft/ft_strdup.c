#include "libft.h"

char *ft_strdup(const char *s)
{
	char *new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_memmove(new, s, ft_strlen(s));
	new[ft_strlen(s)] = '\0';
	return (new);
}
