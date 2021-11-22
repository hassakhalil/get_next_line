/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/22 01:10:38 by hkhalil          ###   ########.fr       */
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
		if (NEXT_LINE)
		{
			line = ft_strdup(NEXT_LINE);
		    //free(NEXT_LINE);
            //free(buf);
            NEXT_LINE = NULL;
		}
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (0);
        buf[ret] = 0;
		if (ret == 0)
			return (line);
		i = 0;
		while (buf[i] != '\n' && i < ret)
			i++;
		if (buf[i] == '\n')
		{
			i++;
			NEXT_LINE = ft_substr(buf, i, BUFFER_SIZE - i + 1);
		}
		else if (!i)
			line = ft_strjoin(line, ft_substr(buf, 0, i + 1));
	}
	return (0);
}

/*#include <fcntl.h>

int main()
{
    //char buff[10];
    int fd = open("get_next_line.c", O_RDWR);
    //char *line = get_next_line(fd);
    printf("%s", get_next_line(fd));
    return (0);
}*/
