/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makegrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 02:33:33 by kmills            #+#    #+#             */
/*   Updated: 2019/04/10 08:26:17 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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



	// i = 0;
	// j = 0;
	// /* рисуем вертикальные линии */
	// while (i < fdf.map.width)
	// {
	// 	xy1(fdf, fdf.map.x + i * 100, fdf.map.y);
	// 	xy2(fdf, fdf.map.x + i * 100, fdf.map.y + (fdf.map.height * 100) - 100);
	// 	draw_line(fdf);
	// 	i++;
	// }
	// /* рисуем горизонтальные линии */
	// while (j < fdf.map.height)
	// {
	// 	xy1(fdf, fdf.map.x, fdf.map.y + j * 100);
	// 	xy2(fdf, fdf.map.x + (fdf.map.width * 100) - 100, fdf.map.y + j * 100);
	// 	draw_line(fdf);
	// 	j++;
	// }
}
