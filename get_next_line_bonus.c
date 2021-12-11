/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:30:55 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/28 01:08:42 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*rest_with_nl(char **rest, int fd)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while (rest[fd][i] != '\n')
		i++;
	line = ft_substr(rest[fd], 0, i + 1);
	if (!line)
		return (0);
	tmp = rest[fd];
	rest[fd] = ft_strdup(&rest[fd][i + 1]);
	if (!rest[fd])
		return (0);
	free(tmp);
	return (line);
}

size_t	read_new_buff(char **rest, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;

	ret = read(fd, buff, BUFFER_SIZE);
	if (ret == -1)
	{
		free(rest[fd]);
		rest[fd] = NULL;
		return (0);
	}
	buff[ret] = 0;
	tmp = rest[fd];
	rest[fd] = ft_strjoin(rest[fd], buff);
	if (!rest[fd])
		return (0);
	free(tmp);
	return (ret);
}

char	*last_line(char **rest, int fd, int ret)
{
	char	*line;

	if (ret == 0 && !ft_strlen(rest[fd]))
	{
		free(rest[fd]);
		rest[fd] = NULL;
		return (0);
	}
	line = ft_strdup(rest[fd]);
	if (!line)
		return (0);
	free(rest[fd]);
	rest[fd] = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	ssize_t		ret;

	if (!rest[fd])
	{
		rest[fd] = ft_strdup("");
		if (!rest[fd])
			return (0);
	}
	while (1)
	{
		if (rest[fd] && ft_strchr(rest[fd], '\n'))
			return (rest_with_nl(rest, fd));
		ret = read_new_buff(rest, fd);
		if (ft_strchr(rest[fd], '\n'))
			return (rest_with_nl(rest, fd));
		else if (ret < BUFFER_SIZE)
			return (last_line(rest, fd, ret));
	}
	return (0);
}
