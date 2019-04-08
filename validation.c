#include "fdf.h"

int		valid(char *str)
{
	int y_count;
	int fd;
	int i;
	int ret;
	char line[BUFF_SIZE + 1];

	i = 0;
	y_count = 0;
	fd = open(str, O_RDONLY);
	while ((ret = read(fd, line, BUFF_SIZE)))
	{
		line[ret] = '\0';
		while (line[i])
		{
			if (line[i] == '\n')
				++y_count;
			++i;
		}
	}
	close (fd);
	return (y_count);
}
