/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawetc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:53:17 by kmills            #+#    #+#             */
/*   Updated: 2019/04/12 23:32:31 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		raduga(t_point *dot)
{
	static long long int	i = 0;
	int						color;

	i += 1;
	if (i % 10 == 0)
		(*dot).colour = (*dot).colour + 1;
	color = (*dot).colour;
	return (color);
}

void	makefongray(t_fdf fdf)
{
	int			i;
	static int	k = 0;
	int			g;

	i = 0;
	if (fdf.buttons[1] == 1)
		k = k > 200 ? 0 : k + 2;
	else
		k = 0;
	while (i < 7680 * 1080)
	{
		fdf.img.str[i] = 29 >> (k % 2);
		fdf.img.str[i + 1] = (29 + k) << ((k % 3) - 2);
		fdf.img.str[i + 2] = (29 + (k * 3)) << (k % 5);
		i += 4;
	}
}

void	if1indraw_line(int *error, int *ds, t_fdf *fdf)
{
	*error -= ds[1];
	(*fdf).koord->x1 += ds[2];
}

void	if2indraw_line(int *error, int *ds, t_fdf *fdf)
{
	*error += ds[0];
	(*fdf).koord->y1 += ds[3];
}
