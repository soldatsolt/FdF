/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:04:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/05 10:17:09 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*makekoor4(int x1, int y1, int x2, int y2)
{
	int		*ko;

	ko = (int *)malloc(sizeof(int) * 4);
	ko[0] = x1;
	ko[1] = y1;
	ko[2] = x2;
	ko[3] = y2;
	return (ko);
}

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
	fdf.img.str[7680 * y + x * 4] = 0xFF;
	fdf.img.str[7680 * y + x * 4 + 1] = 0xFF;
	fdf.img.str[7680 * y + x * 4 + 2] = 0xFF;
}

int		*deltaandsign(int *ko)
{
	int	*rez;

	rez = (int *)malloc(sizeof(int) * 4);
	rez[0] = abs(ko[2] - ko[0]);
	rez[1] = abs(ko[3] - ko[1]);
	if (ko[0] < ko[2])
		rez[2] = 1;
	else
		rez[2] = -1;
	if (ko[1] < ko[3])
		rez[3] = 1;
	else
		rez[3] = -1;
	return (rez);
}

void	draw_line(t_fdf fdf, int *ko)
{
	int		*ds;
	int		error;
	int		error2;

	ds = deltaandsign(ko);
	error = ds[0] - ds[1];
	whitepixel(fdf, ko[2], ko[3]);
	while (ko[0] != ko[2] || ko[1] != ko[3])
	{
		whitepixel(fdf, ko[0], ko[1]);
		error2 = error * 2;
		if (error2 > -ds[1])
		{
			error -= ds[1];
			ko[0] += ds[2];
		}
		if (error2 < ds[0])
		{
			error += ds[0];
			ko[1] += ds[3];
		}
	}
	free(ds);
	free(ko);
	ko = NULL;
}

int		main(void)
{
	t_fdf	fdf;
	int		*ko;

	ko = makekoor4(50, 50, 650, 1020);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1920, 1080, "test");
	fdf.img_ptr = mlx_new_image(fdf.mlx_ptr, 1920, 1080);
	fdf.img.str = mlx_get_data_addr(fdf.img_ptr, &fdf.img.bits_per_pixel, &fdf.img.size_line, &fdf.img.endian);
	printf(" bits_per_pixel = %i\n size_line = %i\n endian = %i\n", fdf.img.bits_per_pixel, fdf.img.size_line, fdf.img.endian);
	printf("S = %s\n", fdf.img.str);
	whitepixel(fdf, 500, 500);
	draw_line(fdf, ko);
	mlx_key_hook(fdf.win_ptr, deal_key, (void *)0);
	mlx_mouse_hook(fdf.win_ptr, deal_mouse, (void *)0);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img_ptr, 0, 0);
	// mlx_destroy_image(mlx_ptr, img_ptr);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
