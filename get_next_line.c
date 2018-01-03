/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:47:43 by cammapou          #+#    #+#             */
/*   Updated: 2018/01/03 17:14:29 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_get_next_line(const int fd, char **line)
{
	return (0);
}

int main(int argc, char **argv)
{
	char buf[BUF_SIZE + 1];
	int fd;
	char *tmp;
	int i;

	ft_bzero(buf, BUF_SIZE);
	fd = open(argv[1], O_RDONLY);
	while ((read(fd, buf, BUF_SIZE)))
	{
		tmp = *ft_strsplit(buf, '\n');
		ft_putstr(buf);
	}
	//tmp = *ft_strsplit(buf, '\n');
	ft_putchar('\n');
	printf("tmp : \n%s\n", tmp);
	close(fd);
	return (0);
}
