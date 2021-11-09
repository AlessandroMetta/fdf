#ifndef __LIBFT_H__
# define __LIBFT_H__

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAX_F 256
# define BUFFER_SIZE 42

void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_realloc(void *ptr, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
void	ft_putstr(const char *str);
int		get_next_line(const int fd, char **line);

#endif
