/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 06:07:14 by kmills            #+#    #+#             */
/*   Updated: 2019/04/11 08:54:13 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	iso(t_point dot, float qx, float qz)
{
	int		p_x;
	int		p_y;
	int		p_z;
	// t_point	dot;

	// dot = *ddot;

	if (dot.z == 10)
		dot.z *= 7;
	p_x = dot.x;
	p_y = dot.y;
	p_z = dot.z;
			// fdf.map.point[j][i].x = (p_x - p_y) * cos(0.523599);
			// fdf.map.point[j][i].y = -p_z + (p_x + p_y) * sin(0.523599);
			// fdf.map.point[j][i].x += 550;
	dot.x = p_x * cos(qz) - p_y * sin(qz);
	dot.y = p_x * sin(qz) + p_y * cos(qz);
	p_y = dot.y;
	dot.y = p_y * cos(qx) - p_z * sin(qx);
			// fdf.map.point[j][i].z = -p_y * sin(0.523599) + p_z * cos(0.523599);
	return (dot);
}