/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 00:41:39 by kmills            #+#    #+#             */
/*   Updated: 2019/04/10 07:10:59 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	whitepixel(t_fdf fdf, int x, int y, int colour)
{
	int	*str;
	str = (int*)fdf.img.str;
	if (x > 0 && y > 0 && x < 1920 && y < 1080)
		str[7680/4 * y + x] = colour << 4;
}

int		*deltaandsign(t_fdf fdf)
{
	int	*rez;

	rez = (int *)malloc(sizeof(int) * 4);
	rez[0] = abs(fdf.koord->x2 - fdf.koord->x1);
	rez[1] = abs(fdf.koord->y2 - fdf.koord->y1);
	if (fdf.koord->x1 < fdf.koord->x2)
		rez[2] = 1;
	else
		rez[2] = -1;
	if (fdf.koord->y1 < fdf.koord->y2)
		rez[3] = 1;
	else
		rez[3] = -1;
	return (rez);
}

void	draw_line(t_fdf fdf, int colour1, int colour2)
{
	int		*ds;
	int		error;
	int		error2;

	ds = deltaandsign(fdf);
	error = ds[0] - ds[1];
	whitepixel(fdf, fdf.koord->x2, fdf.koord->y2, colour2);
	while (fdf.koord->x1 != fdf.koord->x2 || fdf.koord->y1 != fdf.koord->y2)
	{
		whitepixel(fdf, fdf.koord->x1, fdf.koord->y1, colour1);
		error2 = error * 2;
		if (error2 > -ds[1])
		{
			error -= ds[1];
			fdf.koord->x1 += ds[2];
		}
		if (error2 < ds[0])
		{
			error += ds[0];
			fdf.koord->y1 += ds[3];
		}
	}
	free(ds);
}

void	xy1(t_fdf fdf, int x1, int y1)
{
	fdf.koord->x1 = x1;
	fdf.koord->y1 = y1;
}

void	xy2(t_fdf fdf, int x2, int y2)
{
	fdf.koord->x2 = x2;
	fdf.koord->y2 = y2;
}

