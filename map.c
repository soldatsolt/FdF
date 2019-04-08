#include "fdf.h"

int		ft_num_counter(char *str)
{
	int num;
	int flag;

	num = 0;
	flag = 0;
	while (*str)
	{
		if (is_digit(*str) && flag == 0)
		{
			++num;
			flag = 1;
		}
		else if (*str == 32)
			flag = 0
		str++;
	}
	return (num);
}

int		map_maker(char *str, t_map map, int y_count)
{
	int  fd;
	int  x;
	int  len;
	char *line;
	char **nums;

	fd = open(str,  O_RDONLY);
	map->point = (t_point**)malloc(sizeof(t_point*) * y_count);
	map.height = y_count;
	y_count = 0;
	x = 0;
	ken = 0;
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		len = ft_num_counter(line);
		map->(point*) = (t_point*)malloc(sizeof(t_point) * len);
		nums = ft_split(line, ' ');
		while (num[x])
		{
				map-
		}
	}
}
