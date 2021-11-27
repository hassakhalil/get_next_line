/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/27 12:29:06 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char        *buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    char        *line = NULL;
    static char *rest;
    char        *tmp;
    int         i;
    ssize_t     ret;

    rest = ft_strdup("");
    while (1)
    {
        if (ft_strchr(rest, '\n'))
        {
            i = 0;
            while (rest[i] != '\n')
                i++;
            line = ft_substr(rest, 0, i + 1);
            tmp = rest;
            rest = ft_strdup(&rest[i + 1]);
            free(tmp);
            free(buff);
            return (line);
        }
        ret = read(fd, buff, BUFFER_SIZE);
        if (ret == -1)
        {
            free(rest);
            if (line)
                free(line);
            free(buff);
            return (0);
        }
        buff[ret] = 0;
        tmp = rest;
        rest = ft_strjoin(rest, buff);
        free(tmp);
        if (ft_strchr(rest, '\n'))
        {
            i = 0;
            while (rest[i] != '\n')
                i++;
            line = ft_substr(rest, 0, i + 1);
            tmp = rest;
            rest = ft_strdup(&rest[i + 1]);
            free(tmp);
            free(buff);
            free(rest);
            return (line);
        }
        else if (ret < BUFFER_SIZE)
        {
            line = ft_strdup(rest);
            free(rest);
            free(buff);
            return (line);
        }
    }
    return (0);
}

/*#include <fcntl.h>

int main()
{
    int fd = open("41_no_nl", O_RDWR);
    char *line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        line = get_next_line(fd);
    }
    return (0);
}*/
