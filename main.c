/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:04:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/11 16:32:03 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hoook()
{

	return (0);
}

int		loop_hook(t_fdf *fdf)
{
	return (0);
}

void	uvel_z(t_fdf *ffdf, int i, int j)
{
	t_fdf	fdf;

	fdf = *ffdf;
	while (j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			if (fdf.map.point[j][i].k)
				fdf.map.point[j][i].z += 10;
			i++;
		}
		i = 0;
		j++;
	}
}

void	umen_z(t_fdf *ffdf, int i, int j)
{
	t_fdf	fdf;

	fdf = *ffdf;
	while (j < fdf.map.height)
	{
		while (i < fdf.map.width)
		{
			if (fdf.map.point[j][i].k)
				fdf.map.point[j][i].z -= 10;
			i++;
		}
		i = 0;
		j++;
	}
}

int		deal_key(int key, t_fdf *fdf)
{
	// ft_putnbr(key);
	// ft_putchar('\n');
	if (key == 34 && (*fdf).proj.f_i == 0)
		(*fdf).proj.f_i = 1;
	// if (key == 34 && (*fdf).proj.f_i == 1)
	// 	(*fdf).proj.f_i = 0;
	if (key == 53)
		exit(0);
	if (key == 124 || key == 123 || key == 125 || key == 126 || key == 13 || \
	key == 0 || key == 1 || key == 2 || key == 69 || key == 78)
		uprld(key, fdf);
	if (key == 67)
		uvel_z(fdf, 0, 0);
	if (key == 75)
		umen_z(fdf, 0, 0);
	return (0);
}

int mouse_move(int x, int y, t_fdf *fdf)
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
	// if (fdf->mouse.mouse_flag)
	// 	printf("X = %i, Y = %i\n", x, y);
	return (0);
}

int		expose_hook(void *param)
{
	return (0);
}

int		deal_mouse(int mouse, int x, int y, t_fdf *fdf)
{
	if (mouse == 4)
		(*fdf).zoom += 1;
	if (mouse == 5)
		(*fdf).zoom -= 1;
	if (mouse == 1)
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

int mouse_release(int button, int x, int y, t_fdf *fdf)
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

int		doloop(t_fdf *fdf)// ВОТ ТУТ ДОЛЖНО ВСЁ ДЕЛАТЬ
{
	char buffer[100];
	sprintf(buffer, "%10.3f", (*fdf).d3d.ox);
	mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
	ft_bzero((*fdf).img.str, 7680 * 1080);
	make1stgrid(*fdf);
	mlx_put_image_to_window((*fdf).mlx_ptr, (*fdf).win_ptr, (*fdf).img_ptr, 0, 0);
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 40, 80, 0xFFFFFF, "OX ROT:");
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 70, 80, 0xFFFFFF, buffer);
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 40, 100, 0xFFFFFF, "OZ ROT:");
	sprintf(buffer, "%10.3f", (*fdf).d3d.oz);
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 70, 100, 0xFFFFFF, buffer);
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 40, 120, 0xFFFFFF, "Xo,Yo:");
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 120, 120, 0xFFFFFF, ft_itoa((*fdf).map.point[0][0].x));
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 170, 120, 0xFFFFFF, ",");
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 180, 120, 0xFFFFFF, ft_itoa((*fdf).map.point[0][0].y));
	return (0);
}

int		main(int argc,  char **argv)
{
	t_fdf	*ffdf;
	t_fdf	fdf;
	int		y_count;
	int 	i;
	int 	j;

	write(1, "@@\n", 3);
	i = 0;
	j = 0;
	if (argc != 2)
		return (0);
	y_count = valid(argv[1]);
	if (y_count == 0)
	{
		ft_putstr("error_map\n");
		return (0);
	}
	ffdf = (t_fdf*)malloc(sizeof(t_fdf));
	fdf = *ffdf;
	map_maker(argv[1], &fdf, y_count);
	printf(" colour = %d min = %d max = %d\n", fdf.map.point[2][2].colour, fdf.map.min, fdf.map.max);
	fdf.mlx_ptr = mlx_init();
    fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1920, 1080, "test");
    fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, 1920, 1080);
    fdf.img.str = mlx_get_data_addr(fdf.img_ptr, &fdf.img.bits_per_pixel, &fdf.img.size_line, &fdf.img.endian);
    fdf.koord = (t_mkline *)malloc(sizeof(t_mkline));
	fdf.proj.f_i = 0;
	fdf.d3d.ox = 0.5;
	// fdf.d3d.oy = 0.5;
	fdf.d3d.oz = 0.5;
	fdf.zoom = 40;
	fdf.mouse.mouse_flag1 = 0;
	fdf.mouse.mouse_flag2 = 0;
    printf(" bits_per_pixel = %i\n size_line = %i\n endian = %i\n", fdf.img.bits_per_pixel, fdf.img.size_line, fdf.img.endian);
	fdf.map.x = 60;
	fdf.map.y = 40;
    mlx_hook(fdf.win_ptr, 2, 0, deal_key, &(fdf));
	mlx_hook(fdf.win_ptr, 6, 0, mouse_move, &fdf);
    mlx_hook(fdf.win_ptr, 4, 0, deal_mouse, &fdf);
	mlx_hook(fdf.win_ptr, 5, 0, mouse_release, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, cclose, &fdf);
	mlx_loop_hook(fdf.mlx_ptr, doloop, &fdf);
    mlx_loop(fdf.mlx_ptr);
	return (0);
}
