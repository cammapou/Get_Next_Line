/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:47:43 by cammapou          #+#    #+#             */
/*   Updated: 2018/01/05 15:37:44 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 **
 **
 **
 **
 **
 **
 */

int		ft_read(char **argv)
{
	int		fd;
	char	*line;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	ft_get_next_line(fd, &line);
	close(fd);
	return (0);
}

int		ft_get_next_line(const int fd, char **line)
{
	char		buf[BUF_SIZE + 1];
	static int	i;
	static int	k;
	char		**tmp;
	
	i = 0;
	k = i;
	ft_bzero(buf, BUF_SIZE);
	while (read(fd, buf, BUF_SIZE))
	{
		*line = buf;
		ft_putstr(buf);
	}
	/*while (line[i])
	{
		ft_putstr(line[i]);
		ft_putchar('\n');
		if (line[i][k] == '\n')
			break;
		i++;
	}
	ft_putchar('\n');*/
	printf("tmp : \n%s\n", *line);
	
	return (0);
}

int main(int argc, char **argv)
{
	ft_read(argv);
	return (0);
}
