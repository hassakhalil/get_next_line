/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/21 19:01:36 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	ssize_t	ret;
	int		i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	i = 0;
	line = NULL;
	while (1)
	{
		if (ft_strlen(NEXT_LINE))
		{
			line = ft_strdup(NEXT_LINE);
			free(NEXT_LINE);
		}
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = 0;
		if (ret == -1)
			return (0);
		else if (ret == 0)
			return (line);
		i = 0;
		while (buf[i] != '\n' && i < ret)
			i++;
		if (buf[i] == '\n' || buf[i] == EOF)
		{
			if (buf[i] == '\n')
			{
				i++;
				NEXT_LINE = malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
				NEXT_LINE = ft_substr(buf, i, BUFFER_SIZE - i + 1);
			}
			free(buf);
			return (ft_strjoin(line, ft_substr(buf, 0, i + 1)));
		}
		else if (!i)
			line = ft_strjoin(line, ft_substr(buf, 0, i + 1));
	}
	return (0);
}	
