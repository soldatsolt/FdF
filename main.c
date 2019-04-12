/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:04:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/12 22:48:58 by kmills           ###   ########.fr       */
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

int		cclose(void *param)
{
	exit(0);
	return (0);
}

int		doloop(t_fdf *fdf)
{
	mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
	makefongray(*fdf);
	make1stgrid(fdf);
	mlx_put_image_to_window((*fdf).mlx_ptr, (*fdf).win_ptr, \
	(*fdf).img_ptr, 0, 0);
	return (0);
}

t_fdf	fdf_make(t_fdf fdf)
{
	fdf.koord = (t_mkline *)malloc(sizeof(t_mkline));
	fdf.proj.f_i = 0;
	fdf.proj.f_p = 0;
	fdf.d3d.ox = 0;
	fdf.d3d.oy = 0;
	fdf.d3d.oz = 0;
	fdf.nb = 1;
	fdf.nm = 1;
	fdf.zoom = 32768;
	fdf.mouse.mouse_flag1 = 0;
	fdf.mouse.mouse_flag2 = 0;
	fdf.map.x = 60;
	fdf.map.y = 40;
	return (fdf);
}

int		main(int argc, char **argv)
{
	t_fdf	*ffdf;
	t_fdf	fdf;
	int		y_count;

	if (argc != 2)
		return (0);
	y_count = valid(argv[1]);
	if (y_count == 0)
		err_map();
	ffdf = (t_fdf*)malloc(sizeof(t_fdf));
	fdf = *ffdf;
	map_maker(argv[1], &fdf, y_count);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1920, 1080, "test");
	fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, 1920, 1080);
	fdf.img.str = mlx_get_data_addr(fdf.img_ptr, &fdf.img.bits_per_pixel,\
	&fdf.img.size_line, &fdf.img.endian);
	fdf = fdf_make(fdf);
	mlx_hook(fdf.win_ptr, 2, 0, deal_key, &(fdf));
	mlx_hook(fdf.win_ptr, 6, 0, mouse_move, &fdf);
	mlx_hook(fdf.win_ptr, 4, 0, deal_mouse, &fdf);
	mlx_hook(fdf.win_ptr, 5, 0, mouse_release, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, cclose, &fdf);
	mlx_loop_hook(fdf.mlx_ptr, doloop, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
