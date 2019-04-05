/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:04:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/05 09:04:42 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *param)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
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
	fdf.img.str[3200 * y + x * 4] = 0xFF;
	fdf.img.str[3200 * y + x * 4 + 1] = 0xFF;
	fdf.img.str[3200 * y + x * 4 + 2] = 0xFF;
}

int		main(void)
{
	t_fdf	fdf;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 800, 600, "test");
	fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, 800, 600);
	fdf.img.str = mlx_get_data_addr(fdf.img_ptr, &fdf.img.bits_per_pixel, &fdf.img.size_line, &fdf.img.endian);
	printf(" bits_per_pixel = %i\n size_line = %i\n endian = %i\n", fdf.img.bits_per_pixel, fdf.img.size_line, fdf.img.endian);
	printf("S = %s\n", fdf.img.str);
	// fdf.img.str[800 * 100 + 400] = 0xFF;
	// fdf.img.str[800 * 100 + 401] = 0xFF;
	// fdf.img.str[800 * 100 + 402] = 0xFF;
	whitepixel(fdf, 400, 100);
	// draw_line(mlx_ptr, win_ptr, ko);
	mlx_key_hook(fdf.win_ptr, deal_key, (void *)0);
	mlx_mouse_hook(fdf.win_ptr, deal_mouse, (void *)0);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img_ptr, 100, 0);
	// mlx_destroy_image(mlx_ptr, img_ptr);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
