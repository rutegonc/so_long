/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:17:31 by rugoncal          #+#    #+#             */
/*   Updated: 2022/12/11 22:19:05 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* It is a function that reads a file and allows you to read a line
ending with a newline character from a file descriptor. When you call
the function again on the same file, it grabs the next line. */

char	*ft_read_stash(int fd, char *stash)
{
	char	*buff;
	int		nbyte;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	nbyte = 1;
	while (!ft_strchr(stash, '\n') && nbyte != 0)
	{
		nbyte = read(fd, buff, BUFFER_SIZE);
		if (nbyte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbyte] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_new_stash(stash);
	return (line);
}
