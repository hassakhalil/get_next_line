/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/28 01:12:23 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest_with_nl(char *rest)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while (rest[i] != '\n')
		i++;
	line = ft_substr(rest, 0, i + 1);
	if (!line)
		return (0);
	tmp = rest;
	rest = ft_strdup(&rest[i + 1]);
	if (!rest)
		return (0);
	free(tmp);
	return (line);
}

size_t	read_new_buff(char *rest, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;

	ret = read(fd, buff, BUFFER_SIZE);
	if (ret == -1)
	{
		free(rest);
		rest = NULL;
		return (0);
	}
	buff[ret] = 0;
	tmp = rest;
	rest = ft_strjoin(rest, buff);
	if (!rest)
		return (0);
	free(tmp);
	return (ret);
}

char	*last_line(char *rest, int ret)
{
	char	*line;

	if (ret == 0 && !ft_strlen(rest))
	{
		free(rest);
		rest = NULL;
		return (0);
	}
	line = ft_strdup(rest);
	if (!line)
		return (0);
	free(rest);
	rest = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	ssize_t		ret;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	if (!rest)
	{
		rest = ft_strdup("");
		if (!rest)
			return (0);
	}
	while (1)
	{
		if (rest && ft_strchr(rest, '\n'))
			return (rest_with_nl(rest));
		ret = read_new_buff(rest, fd);
		if (ft_strchr(rest, '\n'))
			return (rest_with_nl(rest));
		else if (ret < BUFFER_SIZE)
			return (last_line(rest, ret));
	}
	return (0);
}
