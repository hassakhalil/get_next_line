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
char	*get_next_line(int fd)
{
    char        buff[BUFFER_SIZE + 1];
    char        *line;
    static char *rest[OPEN_MAX];
    char        *tmp;
    int         i;
    ssize_t     ret;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (0);
    if (!rest[fd])
        rest[fd] = ft_strdup("");
    while (1)
    {
        if (rest[fd] && ft_strchr(rest[fd], '\n'))
        {
            i = 0;
            while (rest[fd][i] != '\n')
                i++;
            line = ft_substr(rest[fd], 0, i + 1);
            tmp = rest[fd];
            rest[fd] = ft_strdup(&rest[fd][i + 1]);
            free(tmp);
            return (line);
        }
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
        free(tmp);
        if (ft_strchr(rest[fd], '\n'))
        {
            i = 0;
            while (rest[fd][i] != '\n')
                i++;
            line = ft_substr(rest[fd], 0, i + 1);
            tmp = rest[fd];
            rest[fd] = ft_strdup(&rest[fd][i + 1]);
            free(tmp);
            return (line);
        }
        else if (ret < BUFFER_SIZE)
        {
            if (ret == 0 && !ft_strlen(rest[fd]))
            {
                free(rest[fd]);
                rest[fd] = NULL;
                return (0);
            }
            line = ft_strdup(rest[fd]);
            free(rest[fd]);
            rest[fd] = NULL;
            return (line);
        }
    }
    return (0);
}
