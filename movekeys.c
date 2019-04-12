/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movekeys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 00:38:34 by kmills            #+#    #+#             */
/*   Updated: 2019/04/12 22:51:04 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	uvel_z(t_fdf *ffdf, int i, int j)
{
	t_fdf	fdf;

	(*ffdf).nb *= 1.2;
	(*ffdf).nm = 1;
	fdf = *ffdf;
	while (j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			if (fdf.map.point[j][i].k)
				(*ffdf).map.point[j][i].k *= 1.2;
			if (!fdf.map.point[j][i].k && fdf.map.point[j][i].kz)
				(*ffdf).map.point[j][i].k = (*ffdf).map.point[j][i].kz;
			i++;
		}
		i = 0;
		j++;
	}
}

void	umen_z(t_fdf *ffdf, int i, int j)
{
	t_fdf	fdf;

	(*ffdf).nm *= 1.2;
	(*ffdf).nb = 1;
	fdf = *ffdf;
	while (j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			if (fdf.map.point[j][i].k)
				(*ffdf).map.point[j][i].k /= 1.2;
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
		(*fdf).zoom *= 2;
	if (key == 78)
		(*fdf).zoom /= 2;
}

t_fdf	*zero_buttons(t_fdf *fdf)
{
	(*fdf).buttons[0] = 0;
	(*fdf).buttons[1] = 0;
	(*fdf).buttons[2] = 0;
	return (fdf);
}
