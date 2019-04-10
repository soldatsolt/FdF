/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movekeys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 00:38:34 by kmills            #+#    #+#             */
/*   Updated: 2019/04/10 07:05:04 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	uprld(int key, t_fdf *fdf)
{
	if (key == 126)
		(*fdf).map.y -= 45;
	if (key == 124)
		(*fdf).map.x += 45;
	if (key == 125)
		(*fdf).map.y += 45;
	if (key == 123)
		(*fdf).map.x -= 45;
}
