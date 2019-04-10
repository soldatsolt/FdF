/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makegrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 02:33:33 by kmills            #+#    #+#             */
/*   Updated: 2019/04/10 04:17:42 by kmills           ###   ########.fr       */
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
	/* рисуем вертикальные линии */
	while (i < fdf.map.width)
	{
		xy1(fdf, 200 + i * 60, 200 );
		xy2(fdf, 200 + i * 60, 200 + (fdf.map.height * 60));
		draw_line(fdf);
		i++;
	}
	/* рисуем горизонтальные линии */
	while (j < fdf.map.height)
	{
		xy1(fdf, 200, 200 + j * 60);
		xy2(fdf, 200 + j * 60, 200 + fdf.map.height * 60);
		draw_line(fdf);
		j++;
	}
	
}
