#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (!dst)
		return (0);
	ft_memccpy(dst, src, '\0', dstsize);
	if (dstsize > 0)
		dst[dstsize - 1] = '\0';
	return (ft_strlen(src));
}
