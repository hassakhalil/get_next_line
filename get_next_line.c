/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/23 13:22:08 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char        *buf = malloc(BUFFER_SIZE + 1);
	char        *line = malloc(BUFFER_SIZE + 1);
    char        *tmp0;
    //char        **tmp1;
    static char *NEXT_LINE;
	ssize_t     ret = 0;
	int         i = 0;

    while (1)
	{
        if (!i && ft_strlen(NEXT_LINE))
        {
            line = ft_memcpy(line, NEXT_LINE, ft_strlen(NEXT_LINE) + 1);
            free(NEXT_LINE);
            NEXT_LINE = 0;
        }
        ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
        {
            free(buf);
            free(line);
			return (0);
        }
		if (ret == 0)
        {
            free(buf);
            free(line);
            free(NEXT_LINE);

			return (0);
        }
        buf[ret] = 0;
		i = 0;
		while (buf[i] != '\n' && i < ret)
		    i++;
        tmp0 = ft_substr(buf, 0, i + 1);
        //tmp1 = ft_memcpy(tmp1, line, ft_strlen(line) + 1);
	    line = ft_strjoin(line, tmp0);
       // free(tmp0);
        //free(*tmp1);
        if (buf[i] == '\n')
        {
            i++;
            tmp0 = ft_substr(buf, i, BUFFER_SIZE + 1);
            NEXT_LINE = ft_memcpy(NEXT_LINE, tmp0, ft_strlen(tmp0) + 1);
            free(tmp0);
            free(buf);
            return (line);
        }
    }
	return (0);
}

/*#include <fcntl.h>

int main()
{
    int fd = open("get_next_line.c", O_RDWR);
    char *line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        line = get_next_line(fd);
    }
    return (0);
}*/
