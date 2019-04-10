/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:04:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/10 07:56:08 by kmills           ###   ########.fr       */
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

int		deal_key(int key, t_fdf *fdf)
{
	mlx_do_key_autorepeaton((*fdf).mlx_ptr);
	// ft_putnbr(key);
	// ft_putchar('\n');
	if (key == 53)
		exit(0);
	if (key == 124 || key == 123 || key == 125 || key == 126)
		uprld(key, fdf);
	return (0);
}

int mouse_move(int x, int y, t_fdf *fdf)
{
	if (fdf->mouse.mouse_flag)
	{
			(*fdf).map.x = x - fdf->mouse.mouse_x + (*fdf).img.xx;
			(*fdf).map.y = y - fdf->mouse.mouse_y + (*fdf).img.yy;
	}
	else
	{
		(*fdf).img.xx = (*fdf).map.x;
		(*fdf).img.yy = (*fdf).map.y;
	}
	return (0);
}

int		expose_hook(void *param)
{
	return (0);
}

int		deal_mouse(int mouse, int x, int y, t_fdf *fdf)
{
	if (mouse == 1)
	{
		fdf->mouse.mouse_flag = 1;
		fdf->mouse.mouse_x = x;
		fdf->mouse.mouse_y = y;
	}
	ft_putnbr(mouse);
	ft_putchar('\n');
	return (0);

}

int mouse_release(int button, int x, int y, t_fdf *fdf)
{
	fdf->mouse.mouse_flag = 0;
	return (0);
}

int		cclose(void *param)
{
	exit(0);
	return (0);
}

int		doloop(t_fdf *fdf)// ВОТ ТУТ ДОЛЖНО ВСЁ ДЕЛАТЬ
{
	mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
	ft_bzero((*fdf).img.str, 7680 * 1080);
	make1stgrid(fdf);
	mlx_put_image_to_window((*fdf).mlx_ptr, (*fdf).win_ptr, (*fdf).img_ptr, 0, 0);
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
	printf("map.height = %d map.width = %d map.point[10][18].x = %d map.point[10][18].z = %d map.point[10][18].colour = %d\n", fdf.map.height, fdf.map.width, (fdf.map.point)[10][18].x, (fdf.map.point)[10][18].z, (fdf.map.point)[10][18].colour);
	fdf.mlx_ptr = mlx_init();
    fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1920, 1080, "test");
    fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, 1920, 1080);
    fdf.img.str = mlx_get_data_addr(fdf.img_ptr, &fdf.img.bits_per_pixel, &fdf.img.size_line, &fdf.img.endian);
    fdf.koord = (t_mkline *)malloc(sizeof(t_mkline));
    printf(" bits_per_pixel = %i\n size_line = %i\n endian = %i\n", fdf.img.bits_per_pixel, fdf.img.size_line, fdf.img.endian);
	// xy1((fdf), 50, 650);
    // xy2((fdf), 1500, 780);
    // draw_line((fdf));
	fdf.map.x = 200;
	fdf.map.y = 200;
    mlx_hook(fdf.win_ptr, 2, 0, deal_key, &(fdf));
	mlx_hook(fdf.win_ptr, 6, 0, mouse_move, &fdf);
    mlx_hook(fdf.win_ptr, 4, 0, deal_mouse, &fdf);
	mlx_hook(fdf.win_ptr, 5, 0, mouse_release, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, cclose, &fdf);

	mlx_loop_hook(fdf.mlx_ptr, doloop, &fdf);
    mlx_loop(fdf.mlx_ptr);
	return (0);
}
