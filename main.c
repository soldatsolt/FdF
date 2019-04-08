/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:04:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/09 00:42:51 by kmills           ###   ########.fr       */
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
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	// while (key == 4)
	// 	write(1,"dsaedqdr\n",10);
	if (key == 124 || key == 123 || key == 125 || key == 126)
		uprld(key, fdf);
	return (0);
}

int		expose_hook(void *param)
{
	return (0);
}

int		deal_mouse(int mouse, int x, int y, t_fdf *fdf)
{
	static int k = 0;
	if (mouse == 1 && k == 0)
	{
		xy1(*fdf, x, y);
		k++;
		return (0);
	}
	if (mouse == 1 && k == 1)
	{
		xy2(*fdf, x, y);
		k = 0;
		draw_line(*fdf);
		mlx_put_image_to_window((*fdf).mlx_ptr, (*fdf).win_ptr, (*fdf).img_ptr, 0, 0);
	}
	ft_putnbr(mouse);
	ft_putchar('\n');
	return (0);
}

int		main(int argc,  char **argv)
{
	t_fdf	*ffdf;
	t_fdf	fdf;
	int		y_count;

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
    xy1(fdf, 50, 650);
    xy2(fdf, 1500, 780);
    draw_line(fdf);
    // mlx_key_hook(fdf.win_ptr, deal_key, &(fdf));
    mlx_mouse_hook(fdf.win_ptr, deal_mouse, &(fdf));
    mlx_expose_hook (fdf.win_ptr, expose_hook, &(fdf));
    mlx_hook(fdf.win_ptr, 2, 0, hoook, &(fdf)); // ЭТО ВАЖНО МНЕ КАЖЕТСЯ
    mlx_hook(fdf.win_ptr, 2, 0, deal_key, &fdf);
    mlx_loop_hook(fdf.mlx_ptr, loop_hook, &(fdf));
    mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img_ptr, 0, 0);
    // mlx_destroy_image(fdf.mlx_ptr, fdf.img_ptr);
    mlx_loop(fdf.mlx_ptr);	return (0);
}
