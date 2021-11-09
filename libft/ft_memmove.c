#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
