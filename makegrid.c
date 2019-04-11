/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makegrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 02:33:33 by kmills            #+#    #+#             */
/*   Updated: 2019/04/11 16:29:35 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw2dots(t_fdf fdf, int j1, int i1, int j2, int i2)
{
	xy1(fdf, fdf.map.point[j1][i1].x, fdf.map.point[j1][i1].y);
	xy2(fdf, fdf.map.point[j2][i2].x, fdf.map.point[j2][i2].y);
	draw_line(fdf, (int)fdf.map.point[j1][i1].colour, (int)fdf.map.point[j2][i2].colour);
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
			fdf.map.point[j][i].x = fdf.map.x + i * 2 * fdf.zoom - 1920 / 2;
			fdf.map.point[j][i].y = fdf.map.y + j * 2 * fdf.zoom - 1080 / 2;
			// fdf.map.point[j][i].z *= fdf.zoom;
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
				draw2dots(fdf, j, i, j + 1, i);
			else if (j == fdf.map.height - 1 && i < fdf.map.width - 1)
				draw2dots(fdf, j, i, j, i + 1);
			else if (i < fdf.map.width - 1 && j < fdf.map.height - 1)
			{
				draw2dots(fdf, j, i, j + 1, i);
				draw2dots(fdf, j, i, j, i + 1);
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
