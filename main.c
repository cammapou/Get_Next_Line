#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	get_next_line(fd, &line);
	printf("|%s|\n", line);
	ft_strdel(&line);
	close(fd);
	return (0);
}
