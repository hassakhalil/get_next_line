#include "get_next_line.h"

char	*rest_with_nl(char **rest)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while ((*rest)[i] != '\n')
		i++;
	line = ft_substr((*rest), 0, i + 1);
	tmp = *rest;
	(*rest) = ft_strdup(&(*rest)[i + 1]);
	free(tmp);
	return (line);
}

ssize_t	read_new_buff(char **rest, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	ret = read(fd, buff, BUFFER_SIZE);
	if (ret == -1)
	{
		free(*rest);
		(*rest) = NULL;
		return (0);
	}
	buff[ret] = 0;
	(*rest) = ft_strjoin((*rest), buff);
	return (ret);
}

char	*last_line(char **rest)
{
	char	*line;

	line = ft_strdup(*rest);
	free(*rest);
	(*rest) = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	ssize_t		ret;

	while (1)
	{
		ret = read_new_buff(&rest, fd);
		if (ft_strchr(rest, '\n'))
			return (rest_with_nl(&rest));
		 if (ret < BUFFER_SIZE)
			return (last_line(&rest));
	}
	return (0);
}
