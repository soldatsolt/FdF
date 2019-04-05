/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:04:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/05 05:38:52 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *param)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit (0);
	return (0);
}

int		deal_mouse(int mouse, void *param)
{
	ft_putnbr(mouse);
	ft_putchar('\n');
	return (0);
}

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "test");
	while (x < 500)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		x++;
		y = y + 3;
	}
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_mouse_hook(win_ptr, deal_mouse, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}