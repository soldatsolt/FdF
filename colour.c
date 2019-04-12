/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:42:15 by ergottli          #+#    #+#             */
/*   Updated: 2019/04/12 21:43:15 by ergottli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int		find_min_max(t_point *point, int value, int flag)
{
    if (value > point->y)
        point->y = value;
    if (value < point->x)
        point->x = value;
    if (flag == 1)
        return (point->x);
    if (flag == 2)
        return (point->y);
    return (0);
}

int get_color(int error2, int *ds, t_mkline example, int x, int y, int colour1, int colour2)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (colour1 == colour2)
        return (colour1);
    if (ds[0] > ds[1])		//PIZDEZ
        percentage = percent(example.x1, example.x2, x);
    else
        percentage = percent(example.y1, example.y2, y);
    red = get_light((colour1 >> 16) & 0xFF, (colour2 >> 16) & 0xFF, percentage);
    green = get_light((colour1 >> 8) & 0xFF, (colour2 >> 8) & 0xFF, percentage);
    blue = get_light(colour1 & 0xFF, colour2 & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

int		get_init_colour(int min, int max, int colour1, int colour2, int z)
{
    double	percentage;
    int	red;
    int	green;
    int	blue;

    percentage = percent(min, max, z);
    red = get_light((colour1 >> 16) & 0xFF, (colour2 >> 16) & 0xFF, percentage);
    green = get_light((colour1 >> 8) & 0xFF, (colour2 >> 8) & 0xFF, percentage);
    blue = get_light(colour1 & 0xFF, colour2 & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

