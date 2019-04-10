	while(j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			fdf.map.point[j][i].x = 50 + i * 100;
			fdf.map.point[j][i].y = 50 + j * 100;
			
			i++;
		}
		i = 0;
		j++;
	}