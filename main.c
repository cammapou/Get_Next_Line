#include "get_next_line.h"
#include <stdio.h>
int	main(int argc, char ** argv)
{
	int		fd;
	char	*line;

	fd = 257;
	if (argc != 2)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		write(1, "\n", 1);
		free(line);						
	}
	printf("%d\n", get_next_line(fd, &line));
	close(fd);
	while (1)
	{}
	return (0);
}
