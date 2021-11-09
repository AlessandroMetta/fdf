#include "libft.h"

int	get_next_line(int fd, char **line)
{
	static char		buff[MAX_F][BUFFER_SIZE];
	ssize_t			c_red;
	ssize_t			j;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || fd > MAX_F)
		return (-1);
	
}
