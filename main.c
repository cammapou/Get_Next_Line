#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;
	if (argc != 2)
		ft_putendl("error");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	while(get_next_line(fd, &line) == 1)
	{
		//get_next_line(fd, &line);
		printf("line = |%s|\n", line);
		//write(1, line, ft_strlen(line));
		//ft_putchar('\n');
	}
	//write(1, line, ft_strlen(line));
	//printf("|%s|\n", line);
	ft_strdel(&line);
	close(fd);
	return (0);
}
