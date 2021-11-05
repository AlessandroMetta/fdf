#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of argument\n", 1);
		return 1;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Impossible to open the specific file\n", 1);
		return 1;
	}
	ft_putstr_fd("File open\n", 1);
	close(fd);
	return (0);
}
