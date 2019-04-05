/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:04:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/05 06:15:42 by kmills           ###   ########.fr       */
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

void	draw_line(void *mlx_ptr, void *win_ptr, int *ko)
{
	int		*ds;
	int		error;
	int		error2;

	ds = deltaandsign(ko);
	error = ds[0] - ds[1];
	mlx_pixel_put(mlx_ptr, win_ptr, ko[2], ko[3], 0xFFFFFF);
	while (ko[0] != ko[2] || ko[1] != ko[3])
	{
		mlx_pixel_put(mlx_ptr, win_ptr, ko[0], ko[1], 0xFFFFFF);
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
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		*ko;

	ko = makekoor4(50, 50, 200, 200);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "test");
	draw_line(mlx_ptr, win_ptr, ko);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_mouse_hook(win_ptr, deal_mouse, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
