/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:04:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/05 13:23:42 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *fdf)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	if (key == 124 || key == 123 || key == 125 || key == 126)
	{
		uprld(key, fdf);
	}
	return (0);
}

void	uprld(int key, t_fdf *fdf)
{
	static int u = 0;
	static int r = 0;
	static int d = 0;
	static int l = 0;

	if (key == 126)
	{
		u += 4;
		mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
		mlx_put_image_to_window((*fdf).mlx_ptr, (*fdf).win_ptr, (*fdf).img_ptr, r - l, d - u);
	}
	if (key == 124)
	{
		r += 4;
		mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
		mlx_put_image_to_window((*fdf).mlx_ptr, (*fdf).win_ptr, (*fdf).img_ptr, r - l, d - u);
	}
	if (key == 125)
	{
		d += 4;
		mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
		mlx_put_image_to_window((*fdf).mlx_ptr, (*fdf).win_ptr, (*fdf).img_ptr, r - l, d - u);
	}
	if (key == 123)
	{
		l += 4;
		mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
		mlx_put_image_to_window((*fdf).mlx_ptr, (*fdf).win_ptr, (*fdf).img_ptr, r - l, d - u);
	}
}

int		expose_hook(void *param)
{

	return (0);
}

int		deal_mouse(int mouse, void *param)
{
	ft_putnbr(mouse);
	ft_putchar('\n');
	return (0);
}

void	whitepixel(t_fdf fdf, int x, int y)
{
	fdf.img.str[7680 * y + x * 4] = 0xFF;
	fdf.img.str[7680 * y + x * 4 + 1] = 0xFF;
	fdf.img.str[7680 * y + x * 4 + 2] = 0xFF;
}

int		*deltaandsign(t_fdf fdf)
{
	int	*rez;

	rez = (int *)malloc(sizeof(int) * 4);
	rez[0] = abs(fdf.koord->x2 - fdf.koord->x1);
	rez[1] = abs(fdf.koord->y2 - fdf.koord->y1);
	if (fdf.koord->x1 < fdf.koord->x2)
		rez[2] = 1;
	else
		rez[2] = -1;
	if (fdf.koord->y1 < fdf.koord->y2)
		rez[3] = 1;
	else
		rez[3] = -1;
	return (rez);
}

void	draw_line(t_fdf fdf)
{
	int		*ds;
	int		error;
	int		error2;

	ds = deltaandsign(fdf);
	error = ds[0] - ds[1];
	whitepixel(fdf, fdf.koord->x2, fdf.koord->y2);
	while (fdf.koord->x1 != fdf.koord->x2 || fdf.koord->y1 != fdf.koord->y2)
	{
		whitepixel(fdf, fdf.koord->x1, fdf.koord->y1);
		error2 = error * 2;
		if (error2 > -ds[1])
		{
			error -= ds[1];
			fdf.koord->x1 += ds[2];
		}
		if (error2 < ds[0])
		{
			error += ds[0];
			fdf.koord->y1 += ds[3];
		}
	}
	free(ds);
}

void	xy1(t_fdf fdf, int x1, int y1)
{
	fdf.koord->x1 = x1;
	fdf.koord->y1 = y1;
}

void	xy2(t_fdf fdf, int x2, int y2)
{
	fdf.koord->x2 = x2;
	fdf.koord->y2 = y2;
}

// void	(t_fdf *fdf)
// {

// }

int		main(void)
{
	t_fdf	fdf;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1920, 1080, "test");
	fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, 1920, 1080);
	fdf.img.str = mlx_get_data_addr(fdf.img_ptr, &fdf.img.bits_per_pixel, &fdf.img.size_line, &fdf.img.endian);
	fdf.koord = (t_mkline *)malloc(sizeof(t_mkline));
	printf(" bits_per_pixel = %i\n size_line = %i\n endian = %i\n", fdf.img.bits_per_pixel, fdf.img.size_line, fdf.img.endian);
	xy1(fdf, 50, 650);
	xy2(fdf, 1500, 780);
	draw_line(fdf);
	mlx_key_hook(fdf.win_ptr, deal_key, &(fdf));
	mlx_mouse_hook(fdf.win_ptr, deal_mouse, &(fdf));
	mlx_expose_hook (fdf.win_ptr, expose_hook, &(fdf));
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img_ptr, 0, 0);
	// mlx_destroy_image(fdf.mlx_ptr, fdf.img_ptr);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
