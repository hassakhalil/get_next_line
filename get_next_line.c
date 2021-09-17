#icnlude "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf[BUF_SIZE];
	int	ret;

	while (ret = read(fd, buf, BUF_SIZE))
		buf[ret] = 0;

}
