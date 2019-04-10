/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makegrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 02:33:33 by kmills            #+#    #+#             */
/*   Updated: 2019/04/10 09:11:24 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw2dots(t_fdf fdf, t_point dot1, t_point dot2)
{
	// t_fdf fdf;

	// fdf = *ffdf;
	xy1(fdf, dot1.x, dot1.y);
	xy2(fdf, dot2.x, dot2.y);
	draw_line(fdf);

}

void	make1stgrid(t_fdf *ffdf)
{
	t_fdf	fdf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fdf = *ffdf;


	while(j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			fdf.map.point[j][i].x = fdf.map.x + i * 100;
			fdf.map.point[j][i].y = fdf.map.y + j * 100;
			whitepixel(fdf, fdf.map.point[j][i].x, fdf.map.point[j][i].y);
			i++;
		}
		i = 0;
		j++;
	}



	i = 0;
	j = 0;
	while (j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			if (i == fdf.map.width - 1 && j < fdf.map.height - 1)
			{
				draw2dots(fdf, fdf.map.point[j][i], fdf.map.point[j + 1][i]);
				// xy1(fdf, fdf.map.point[j][i].x, fdf.map.point[j][i].y);
				// xy2(fdf, fdf.map.point[j + 1][i].x, fdf.map.point[j + 1][i].y);
				// draw_line(fdf);
			}
			else if (j == fdf.map.height - 1 && i < fdf.map.width - 1)
			{
				draw2dots(fdf, fdf.map.point[j][i], fdf.map.point[j][i + 1]);
				// xy1(fdf, fdf.map.point[j][i].x, fdf.map.point[j][i].y);
				// xy2(fdf, fdf.map.point[j][i + 1].x, fdf.map.point[j][i + 1].y);
				// draw_line(fdf);
			}
			else if (i < fdf.map.width - 1 && j < fdf.map.height - 1)
			{
				draw2dots(fdf, fdf.map.point[j][i], fdf.map.point[j + 1][i]);
				draw2dots(fdf, fdf.map.point[j][i], fdf.map.point[j][i + 1]);
				// xy1(fdf, fdf.map.point[j][i].x, fdf.map.point[j][i].y);
				// xy2(fdf, fdf.map.point[j][i + 1].x, fdf.map.point[j][i + 1].y);
				// draw_line(fdf);
				// xy1(fdf, fdf.map.point[j][i].x, fdf.map.point[j][i].y);
				// xy2(fdf, fdf.map.point[j + 1][i].x, fdf.map.point[j + 1][i].y);
				// draw_line(fdf);
			}
			i++;
		}
		i = 0;
		j++;
	}
}
