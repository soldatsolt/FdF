/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 06:07:14 by kmills            #+#    #+#             */
/*   Updated: 2019/04/11 07:57:04 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_fdf *ffdf, int i, int j)
{
	t_fdf	fdf;
	int		p_x;
	int		p_y;
	int		p_z;

	fdf = *ffdf;
	while (j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			if (fdf.map.point[j][i].z == 10)
				fdf.map.point[j][i].z *= 7;
			p_x = fdf.map.point[j][i].x;
			p_y = fdf.map.point[j][i].y;
			p_z = fdf.map.point[j][i].z;
			// fdf.map.point[j][i].x = (p_x - p_y) * cos(0.523599);
			// fdf.map.point[j][i].y = -p_z + (p_x + p_y) * sin(0.523599);
			// fdf.map.point[j][i].x += 550;
			fdf.map.point[j][i].y = p_y * cos((fdf).d3d.oz) + p_z * sin((fdf).d3d.oz);
			// fdf.map.point[j][i].z = -p_y * sin(0.523599) + p_z * cos(0.523599);
			i++;
		}
		i = 0;
		j++;
	}
	// (fdf).proj.f_i = 0;
}