/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:04:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/05 05:59:06 by kmills           ###   ########.fr       */
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

void	draw_line(void *mlx_ptr, void *win_ptr, int *ko)
{
    const int deltaX = abs(ko[2] - ko[0]);
    const int deltaY = abs(ko[3] - ko[1]);
    const int signX = ko[0] < ko[2] ? 1 : -1;
    const int signY = ko[1] < ko[3] ? 1 : -1;
	int		error = deltaX - deltaY;

	mlx_pixel_put(mlx_ptr, win_ptr, ko[2], ko[3], 0xFFFFFF);
    while(ko[0] != ko[2] || ko[1] != ko[3]) 
   {
        mlx_pixel_put(mlx_ptr, win_ptr, ko[0], ko[1], 0xFFFFFF);
        const int error2 = error * 2;
        //
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            ko[0] += signX;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            ko[1] += signY;
        }
    }
}

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		*ko;

	ko = makekoor4(50 ,50 ,200 ,200);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "test");

	draw_line(mlx_ptr, win_ptr, ko);

	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_mouse_hook(win_ptr, deal_mouse, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}