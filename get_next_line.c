/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/23 07:36:07 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	ssize_t	ret;
	int		i;
    int     flag;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	i = 0;
    line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!line)
        return (0);
    line[i] = 0;
    if (NEXT_LINE)
        flag = 0;
    else
        flag = 1;
	while (1)
	{
		if (flag == 1)
		{
         //   printf("----------------flag==1-----------------------");
            flag = 0;
			line = ft_strdup(NEXT_LINE);
            return (0);
		    free(NEXT_LINE);
            free(buf);
		}
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (0);
		if (ret == 0)
			return (line);
        buf[ret] = 0;
		i = 0;
		while (buf[i] != '\n' && i < ret)
			i++;
		if (buf[i] == '\n' && !flag)
		{
       //    printf(" ------------------------newlinefound--------------------");
            flag = 1;
			i++;
			NEXT_LINE = ft_substr(buf, i, BUFFER_SIZE - i + 1);
            if (!NEXT_LINE)
                    return (0);
		}
        else
        {
		    line = ft_strjoin(line, ft_substr(buf, 0, i + 1));
           // printf("----------------------lastif-------------------------");
        
	    }
    }
	return (0);
}

//#include <fcntl.h>

//int main()
//{
 //   int fd = open("get_next_line.c", O_RDWR);
  //  char *line = get_next_line(fd);
 //   return (0);
//}
