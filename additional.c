/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:18:07 by ergottli          #+#    #+#             */
/*   Updated: 2019/04/12 22:51:50 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		rec_col(t_mkline koord, int colour1, int colour2)
{
	t_point rec;

	rec.x = koord.x1;
	rec.y = koord.y1;
	rec.z = koord.x2;
	rec.colour = koord.y2;
	rec.k = colour1;
	rec.kz = colour2;
	return (rec);
}
