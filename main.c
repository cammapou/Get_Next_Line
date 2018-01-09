#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	get_next_line(fd, &line);
	printf("\nline : |%s|\n", line);
	//ft_strdel(&line);
}
