/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:04:28 by kmills            #+#    #+#             */
/*   Updated: 2019/04/12 23:55:53 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
