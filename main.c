#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("line |%s|\n", line);
	//ft_strdel(&line);
}
