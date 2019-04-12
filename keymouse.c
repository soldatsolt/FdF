/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:32:55 by kmills            #+#    #+#             */
/*   Updated: 2019/04/12 23:35:39 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *fdf)
{
	if (key == 18)
		fdf = zero_buttons(fdf);
	if (key == 8)
		(*fdf).buttons[1] = 1;
	if (key == 19)
		(*fdf).buttons[0] = 1;
	if (key == 20)
		(*fdf).buttons[2] = 1;
	if (key == 34)
		(*fdf).proj.f_i = 1;
	if (key == 35)
		(*fdf).proj.f_p = 1;
	if (key == 53)
		exit(0);
	if (key == 124 || key == 123 || key == 125 || key == 126 || key == 13 || \
	key == 0 || key == 1 || key == 2 || key == 69 || key == 78 || key == 12 \
	|| key == 14)
		uprld(key, fdf);
	if (key == 7)
		uvel_z(fdf, 0, 0);
	if (key == 6)
		umen_z(fdf, 0, 0);
	return (0);
}

int		mouse_move(int x, int y, t_fdf *fdf)
{
	if (fdf->mouse.mouse_flag1 && x < 1920 && y < 1080)
	{
		(*fdf).map.x = x - fdf->mouse.mouse_x + (*fdf).img.xx;
		(*fdf).map.y = y - fdf->mouse.mouse_y + (*fdf).img.yy;
	}
	else if (fdf->mouse.mouse_flag2 && x < 1920 && y < 1080)
	{
		(*fdf).d3d.oz = (float)(x - fdf->mouse.mouse_x + (*fdf).img.xxx) / 500;
		(*fdf).d3d.ox = (float)(y - fdf->mouse.mouse_y + (*fdf).img.yyy) / 500;
	}
	else if (x < 1920 && y < 1080)
	{
		(*fdf).img.xx = (*fdf).map.x;
		(*fdf).img.yy = (*fdf).map.y;
		(*fdf).img.xxx = (*fdf).d3d.oz * 500;
		(*fdf).img.yyy = (*fdf).d3d.ox * 500;
	}
	return (0);
}

int		deal_mouse(int mouse, int x, int y, t_fdf *fdf)
{
	if (mouse == 4 && (*fdf).zoom < 524287)
		(*fdf).zoom *= 2;
	if (mouse == 5 && (*fdf).zoom > 512)
		(*fdf).zoom /= 2;
	if (mouse == 1 && x > 0 && y > 0)
	{
		fdf->mouse.mouse_flag1 = 1;
		fdf->mouse.mouse_x = x;
		fdf->mouse.mouse_y = y;
	}
	if (mouse == 2)
	{
		fdf->mouse.mouse_flag2 = 1;
		fdf->mouse.mouse_x = x;
		fdf->mouse.mouse_y = y;
	}
	ft_putnbr(mouse);
	ft_putchar('\n');
	return (0);
}

int		mouse_release(int button, int x, int y, t_fdf *fdf)
{
	fdf->mouse.mouse_flag1 = 0;
	fdf->mouse.mouse_flag2 = 0;
	return (0);
}
