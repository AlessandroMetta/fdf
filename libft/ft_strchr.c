#include "libft.h"

char *strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != c || s[i] != '\0')
		i++;
	if (s[i] == c)
		return ((char *)s + i);
	return 0;
}
