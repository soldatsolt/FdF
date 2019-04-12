/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:42:15 by ergottli          #+#    #+#             */
/*   Updated: 2019/04/12 23:32:39 by ergottli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		find_min_max(int value, int flag)
{
	static int min = 2147483647;
	static int max = -2147483648;

	if (value > max)
		max = value;
	if (value < min)
		min = value;
	if (flag == 1)
		return (min);
	if (flag == 2)
		return (max);
	return (0);
}

int		get_color(int *ds, int x, int y, t_point col)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (col.k == col.kz)
		return (col.k);
	if (ds[0] > ds[1])
		percentage = percent(col.x, col.z, x);
	else
		percentage = percent(col.y, col.colour, y);
	red = get_light((col.k >> 16) & 0xFF, (col.kz >> 16) & 0xFF, percentage);
	green = get_light((col.k >> 8) & 0xFF, (col.kz >> 8) & 0xFF, percentage);
	blue = get_light(col.k & 0xFF, col.kz & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int		get_init_colour(t_map map, int colour1, int colour2, int z)
{
	double	percentage;
	int		red;
	int		green;
	int		blue;

	percentage = percent(map.min, map.max, z);
	red = get_light((colour1 >> 16) & 0xFF, (colour2 >> 16) & 0xFF, percentage);
	green = get_light((colour1 >> 8) & 0xFF, (colour2 >> 8) & 0xFF, percentage);
	blue = get_light(colour1 & 0xFF, colour2 & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
