#icnlude "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf[BUF_SIZE];
	char	*line;
	size_t	ret;
	int		i = 0;

	if (!count)
	{
		buf = malloc(sizeof(char) * BUF_SIZE);
		ret = read(fd, buf, BUF_SIZE);
		if (!ret)
			return (0);
	}
	while (buf[index] != EOF && index < ret)
	{
		if (buff[index] == '\n')
			break;
		index++;
	}
	line = malloc(sizeof(char) * (index + 2));
	next_line = malloc(sizeof(char) * (ret - index + 1));
	if (!line || !next_line)
		return (0);
	if (ret = index + 1 || buf)
		index = 0;
	return ((char *)ft_substr(buf, Count, i + 1));
}
