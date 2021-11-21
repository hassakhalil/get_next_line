/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/21 12:51:43 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	ssize_t	ret;
	int		i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!buf)
		return (0);
	while (1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (0);
		else if (ret == 0)
			return (line);
		i = 0;
		while (buf[i] != '\n' && buf[i] != EOF && i < BUFFER_SIZE)
			i++;
		if (buf[i] == '\n')
		{
			i++;
			line = ft_strjoin(line, ft_substr(buf, 0, i + 1));
			return (line);
		}
		line = ft_strjoin(line, ft_substr(buf, 0, i + 1));
	}
	return (line);
}	
