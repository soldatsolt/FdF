/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makegrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 02:33:33 by kmills            #+#    #+#             */
/*   Updated: 2019/04/11 15:46:46 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw2dots(t_fdf fdf, t_point dot1, t_point dot2)
{
	xy1(fdf, dot1.x, dot1.y);
	xy2(fdf, dot2.x, dot2.y);
	draw_line(fdf);

}

t_point	dimension3(t_point dot, float qx, float qz)
{
	int		p_x;
	int		p_y;
	int		p_z;

	// if (dot.z == 10)
	// 	dot.z *= 7;
	p_x = dot.x;
	p_y = dot.y;
	p_z = dot.z;
	dot.x = 1920 / 2 + p_x * cos(qz) - p_y * sin(qz);
	dot.y = p_x * sin(qz) + p_y * cos(qz);
	p_y = dot.y;
	dot.y = 1080 / 2 + p_y * cos(qx) - p_z * sin(qx);
	return (dot);
}

void	make1stkoords(t_fdf fdf, int i, int j)
{
	while (j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			fdf.map.point[j][i].x = fdf.map.x + i * 8 * fdf.zoom - 1920 / 2;
			fdf.map.point[j][i].y = fdf.map.y + j * 8 * fdf.zoom - 1080 / 2;
			fdf.map.point[j][i] = dimension3((fdf.map.point[j][i]), \
			(fdf).d3d.ox, (fdf).d3d.oz);
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
