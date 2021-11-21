#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf[BUF_SIZE];
	char	line[BUFF_size];
	size_t	ret;
	int		i;

	buf = malloc(sizeof(char) * (BUF_SIZE));
	if (!buf)
		return (0);
	while (1)
	{
		ret = read(fd, buf, BUF_SIZE);
		if (ret == -1)
			reuturn (0);
		else if (ret == 0)
			return (line);
		i = 0;
		while (buf[i] != '\n' && buf[i] != EOF && i < BUF_SIZE)
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
