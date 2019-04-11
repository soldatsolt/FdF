/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 06:07:14 by kmills            #+#    #+#             */
/*   Updated: 2019/04/11 11:34:42 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	dimension3(t_point dot, float qx, float qz)
{
	int		p_x;
	int		p_y;
	int		p_z;

	if (dot.z == 10)
		dot.z *= 7;
	p_x = dot.x;
	p_y = dot.y;
	p_z = dot.z;
	dot.x = 1920 / 2 + p_x * cos(qz) - p_y * sin(qz);
	dot.y = p_x * sin(qz) + p_y * cos(qz);
	p_y = dot.y;
	dot.y = 1080 / 2 + p_y * cos(qx) - p_z * sin(qx);
	return (dot);
}