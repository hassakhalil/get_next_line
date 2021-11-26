/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/26 08:54:12 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char        *buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    char        *line = NULL;
    static char *rest = NULL;
    char        *tmp;
    int         i;
    ssize_t     ret;

    while (1)
    {
        if (rest && ft_strchr(rest, '\n'))
        {
            i = 0;
            while (rest[i] != '\n')
                 i++;
            line = ft_substr(rest, 0, i + 1);
            tmp = rest;
            rest = ft_substr(rest, i + 1, ft_strlen(rest) - i);
            free(tmp);
            free(buff);
            return (line);
        }
        ret = read(fd, buff, BUFFER_SIZE);
        if (buff[ret] == EOF)
            ret = 0;
        if (ret == -1 || ret == 0)
        {
            if (line)
                free(line);
            if (rest)
                free(rest);
            free(buff);
            return(0);
        }
        buff[ret] = 0;
        if (ft_strchr(buff, '\n'))
        {
            i = 0;
            while (buff[i] != '\n')
                i++;
            tmp = ft_substr(buff, 0, i + 1);
            line = ft_strjoin(rest, tmp);
            free(tmp);
            tmp = rest;
            rest = ft_substr(buff, i + 1, ft_strlen(buff) - i);
            free(tmp);
            free(buff);
            return (line);
        }
        else
        {
            tmp = rest;
            rest = ft_strjoin(rest, buff);
            free(tmp);
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
