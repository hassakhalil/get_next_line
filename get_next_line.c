#icnlude "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf[BUF_SIZE + 1];
	int		ret;

	ret = read(fd, buf, BUF_SIZE);
}
