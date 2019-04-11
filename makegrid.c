/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makegrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 02:33:33 by kmills            #+#    #+#             */
/*   Updated: 2019/04/11 06:02:10 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw2dots(t_fdf fdf, t_point dot1, t_point dot2)
{
	xy1(fdf, dot1.x, dot1.y);
	xy2(fdf, dot2.x, dot2.y);
	draw_line(fdf);

}

void	make1stkoords(t_fdf fdf, int i, int j)
{
	int p_x;
	int p_y;

	while (j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			fdf.map.point[j][i].x = fdf.map.x + i * 80;
			fdf.map.point[j][i].y = fdf.map.y + j * 80;
			if (fdf.map.point[j][i].z == 10)
				fdf.map.point[j][i].z *= 7;
			p_x = fdf.map.point[j][i].x;
			p_y = fdf.map.point[j][i].y;
			fdf.map.point[j][i].x = (p_x - p_y) * cos(0.523599);
			fdf.map.point[j][i].y = -fdf.map.point[j][i].z + (p_x + p_y) * sin(0.523599);
			i++;
		}
		i = 0;
		j++;
	}

}

void	makelinksdraw(t_fdf fdf, int i, int j)
{
	while (j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			if (i == fdf.map.width - 1 && j < fdf.map.height - 1)
				draw2dots(fdf, fdf.map.point[j][i], fdf.map.point[j + 1][i]);
			else if (j == fdf.map.height - 1 && i < fdf.map.width - 1)
				draw2dots(fdf, fdf.map.point[j][i], fdf.map.point[j][i + 1]);
			else if (i < fdf.map.width - 1 && j < fdf.map.height - 1)
			{
				draw2dots(fdf, fdf.map.point[j][i], fdf.map.point[j + 1][i]);
				draw2dots(fdf, fdf.map.point[j][i], fdf.map.point[j][i + 1]);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	make1stgrid(t_fdf fdf)
{
	make1stkoords(fdf, 0, 0);
	makelinksdraw(fdf, 0, 0);
}
