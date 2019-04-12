/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makegrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 02:33:33 by kmills            #+#    #+#             */
/*   Updated: 2019/04/12 23:08:15 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw2dots(t_fdf fdf, t_point *dot1, t_point *dot2)
{
	if ((*dot1).x < 5000 && (*dot1).y < 3000 && \
	(*dot2).x < 5000 && (*dot2).y < 3000)
	{
		xy1(fdf, (*dot1).x, (*dot1).y);
		xy2(fdf, (*dot2).x, (*dot2).y);
		if (fdf.buttons[0] == 1)
			draw_line(fdf, raduga((dot1)), \
			raduga((dot2)));
		else
			draw_line(fdf, (*dot1).colour, \
			(*dot2).colour);
	}
}

t_point	dimension3(t_point dot, float qx, float qz)
{
	int		p_x;
	int		p_y;
	int		p_z;

	p_x = dot.x;
	p_y = dot.y;
	p_z = (int)dot.z;
	dot.x = 1920 / 2 + p_x * cos(qz) - p_y * sin(qz);
	dot.y = p_x * sin(qz) + p_y * cos(qz);
	p_y = dot.y;
	dot.y = 1080 / 2 + p_y * cos(qx) - p_z * sin(qx);
	return (dot);
}

void	make1stkoords(t_fdf fdf, int i, int j)
{
	if (fdf.proj.f_i)
		ft_putnbr(fdf.proj.f_i);
	while (j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			fdf.map.point[j][i].x = fdf.map.x + i * 80 * \
			fdf.zoom / 32768 - 1920 / 2;
			fdf.map.point[j][i].y = fdf.map.y + j * 80 * \
			fdf.zoom / 32768 - 1080 / 2;
			fdf.map.point[j][i].z = fdf.map.point[j][i].k * fdf.zoom / 32768;
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
				draw2dots(fdf, &fdf.map.point[j][i], &fdf.map.point[j + 1][i]);
			else if (j == fdf.map.height - 1 && i < fdf.map.width - 1)
				draw2dots(fdf, &fdf.map.point[j][i], &fdf.map.point[j][i + 1]);
			else if (i < fdf.map.width - 1 && j < fdf.map.height - 1)
			{
				draw2dots(fdf, &fdf.map.point[j][i], &fdf.map.point[j + 1][i]);
				draw2dots(fdf, &fdf.map.point[j][i], &fdf.map.point[j][i + 1]);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	make1stgrid(t_fdf *ffdf)
{
	t_fdf	fdf;

	fdf = *ffdf;
	if (fdf.proj.f_i)
	{
		(*ffdf).d3d.ox = 0.523599;
		(*ffdf).d3d.oz = -0.523599;
		(*ffdf).map.x = 260;
		(*ffdf).map.y = 100;
		(*ffdf).zoom = 32768;
	}
	if (fdf.proj.f_p)
	{
		(*ffdf).d3d.ox = 0;
		(*ffdf).d3d.oz = 0;
		(*ffdf).map.x = 217;
		(*ffdf).map.y = 136;
		(*ffdf).zoom = 32768;
	}
	make1stkoords(fdf, 0, 0);
	makelinksdraw(fdf, 0, 0);
	(*ffdf).proj.f_i = 0;
	(*ffdf).proj.f_p = 0;
}
