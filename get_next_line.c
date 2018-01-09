/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:47:43 by cammapou          #+#    #+#             */
/*   Updated: 2018/01/09 17:13:52 by cammapou         ###   ########.fr       */
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

int		get_next_line(const int fd, char **line)
{
	char			buf[BUF_SIZE + 1];
	static char		*tmp;
	int i;

	i = 0;
	ft_bzero(buf, BUF_SIZE);
	if ((*line = (char *)malloc(sizeof(char) * BUF_SIZE + 1)) == NULL)
		return (0);
	while (read(fd, buf, BUF_SIZE))
	{
		if (ft_strchr(buf, '\n'))
			break;
		//printf("%s", buf);
		*line = ft_strjoin(*line, buf);
		return (1);
			//ft_putstr(buf);
	}
	return (0);
}
