/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movekeys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 00:38:34 by kmills            #+#    #+#             */
/*   Updated: 2019/04/12 17:57:45 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	umenzoom(t_fdf *ffdf, int i, int j)
{
	t_fdf	fdf;

	fdf = *ffdf;
	(*ffdf).zoom /= 2;
	while (j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			// fdf.map.point[j][i].z *= fdf.zoom / (fdf.zoom * 2);
			i++;
		}
		i = 0;
		j++;
	}
}

void	uvelzoom(t_fdf *ffdf, int i, int j)
{
	t_fdf	fdf;

	fdf = *ffdf;
	(*ffdf).zoom *= 2;
	while (j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			// fdf.map.point[j][i].z *= fdf.zoom / (fdf.zoom / 2);
			i++;
		}
		i = 0;
		j++;
	}
}

void	uprld(int key, t_fdf *fdf)
{
	if (key == 126)
		(*fdf).d3d.ox -= 0.05;
	if (key == 124)
		(*fdf).d3d.oz += 0.05;
	if (key == 125)
		(*fdf).d3d.ox += 0.05;
	if (key == 123)
		(*fdf).d3d.oz -= 0.05;
	if (key == 12)
		(*fdf).d3d.oy += 0.05;
	if (key == 14)
		(*fdf).d3d.oy -= 0.05;
	if (key == 0)
		(*fdf).map.x -= 45;
	if (key == 1)
		(*fdf).map.y += 45;
	if (key == 2)
		(*fdf).map.x += 45;
	if (key == 13)
		(*fdf).map.y -= 45;
	if (key == 69)
		uvelzoom(fdf, 0, 0);
	if (key == 78)
		umenzoom(fdf, 0, 0);
}
