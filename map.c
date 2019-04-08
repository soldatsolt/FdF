#include "fdf.h"

int		ft_num_counter(char *str)
{
	int num;
	int flag;

	num = 0;
	flag = 0;
	while (*str)
	{
		if (ft_isdigit(*str) && flag == 0)
		{
			++num;
			flag = 1;
		}
		else if (*str == 32)
			flag = 0;
		str++;
	}
	return (num);
}

int		map_maker(char *str, t_fdf *fdf, int y_count)
{
	int  fd;
	int  x;
	int  len;
	char *line;
	char **num;

	fd = open(str,  O_RDONLY);
	fdf->map.point = (t_point**)malloc(sizeof(t_point*) * y_count);
	fdf->map.height = y_count;
	y_count = 0;
	x = 0;
	len = 0;
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		len = ft_num_counter(line);
		(fdf->map.point)[y_count] = (t_point*)malloc(sizeof(t_point) * len);
		num = ft_strsplit(line, ' ');
		while (num[x])
		{
				(fdf->map.point)[y_count][x].x = x;
				(fdf->map.point)[y_count][x].y = y_count;
				(fdf->map.point)[y_count][x].z = ft_atoi(num[x]);
				(fdf->map.point)[y_count][x].colour = 16777215;
				++x;
		}
		fdf->map.width = x;
		y_count++;
	}
	return (1);
}
