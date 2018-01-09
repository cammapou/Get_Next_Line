/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:47:43 by cammapou          #+#    #+#             */
/*   Updated: 2018/01/09 14:50:38 by cammapou         ###   ########.fr       */
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
	
	ft_bzero(buf, BUF_SIZE);
	while (read(fd, buf, BUF_SIZE))
	{
		if (ft_strchr(buf, '\n'))
		{
			*line = ft_strjoin(*line, buf);
		}
		//ft_putstr(buf);
	}
	return (0);
}
