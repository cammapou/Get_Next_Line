#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		write(1, line, strlen(line));
	}
	close(fd);
	//get_next_line(fd, &line);
	//printf("\nline : |%s|\n", line);
	ft_strdel(&line);
	return (0);
}
