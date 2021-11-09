#include "libft.h"

void *ft_realloc(void *ptr, size_t size)
{
	void *new;

	new = malloc(size);
	if (!new)
		return(NULL);
	ft_bzero(new, size);
	ft_memmove(new, ptr, ft_strlen((char *)ptr));
	free(ptr);
	ptr = NULL;
	return (new);
}
