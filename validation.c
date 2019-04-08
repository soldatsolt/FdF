#include "fdf.h"

int		valid(char *str)
{
	int y_count;
	int fd;
	char line[BUFF_SIZE + 1];

	y_count = 0;
	fd = open(str, O_RDONLY);
	while (ret = read(fd, line, BUFF_SIZE))
	{
		line[ret] = '\0';
		while (*line)
		{
			if (*line == '\n')
				++y_count;
			line++;
		}
	}
	return (y_count);
}
