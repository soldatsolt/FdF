/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movekeys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 00:38:34 by kmills            #+#    #+#             */
/*   Updated: 2019/04/11 11:37:16 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (key == 0)
		(*fdf).map.x -= 45;
	if (key == 1)
		(*fdf).map.y += 45;
	if (key == 2)
		(*fdf).map.x += 45;
	if (key == 13)
		(*fdf).map.y -= 45;
	if (key == 69)
		(*fdf).zoom += 1;
	if (key == 78)
		(*fdf).zoom -= 1;
}
