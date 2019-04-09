/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movekeys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 00:38:34 by kmills            #+#    #+#             */
/*   Updated: 2019/04/09 04:56:16 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	upr_l(t_fdf *fdf, int *u, int d, int r_l)
{
	*u = *u + 4;
	(*fdf).img.x = r_l;
	(*fdf).img.y = d - *u;
}

void	rid_u(t_fdf *fdf, int *r, int l, int d_u)
{
	*r = *r + 4;
	(*fdf).img.x = *r - l;
	(*fdf).img.y = d_u;
}

void	dor_l(t_fdf *fdf, int *d, int u, int r_l)
{
	*d = *d + 4;
	(*fdf).img.x = r_l;
	(*fdf).img.y = *d - u;
}

void	led_u(t_fdf *fdf, int *l, int r, int d_u)
{
	*l = *l + 4;
	(*fdf).img.x = r - *l;
	(*fdf).img.y = d_u;
}

void	uprld(int key, t_fdf *fdf)
{
	static int u = 0;
	static int r = 0;
	static int d = 0;
	static int l = 0;

	if (key == 126)
		upr_l(fdf, &u, d, r - l);
	if (key == 124)
		rid_u(fdf, &r, l, d - u);
	if (key == 125)
		dor_l(fdf, &d, u, r - l);
	if (key == 123)
		led_u(fdf, &l, r, d - u);
}
