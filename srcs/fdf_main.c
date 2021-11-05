#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putstr("Wrong number of argument\n");
		return 1;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Impossible to open the specific file\n");
		return 1;
	}

}
