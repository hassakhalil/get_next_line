#icnlude "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf[BUF_SIZE + 1];
	char	*line;
	size_t	ret;
	int		i = 0;

	buf = malloc(BUF_SIZE + 1);
	ret = read(fd, buf, BUF_SIZE);
	while (ret)
	{
		if (buff[i] = '\n')
			break;
		i++;
		ret--;
	}

}
