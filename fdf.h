/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:18:18 by kmills            #+#    #+#             */
/*   Updated: 2019/04/05 15:07:12 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"

#include <mlx.h>
#include <math.h>

typedef struct	s_mkline
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}				t_mkline;

typedef struct	s_img
{
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*str;
}				t_img;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_img		img;
	t_mkline	*koord;
}				t_fdf;

int		deal_key(int key, t_fdf *fdf);
int		expose_hook(void *param);
int		deal_mouse(int mouse, int x, int y, t_fdf *fdf);
void	whitepixel(t_fdf fdf, int x, int y);
int		*deltaandsign(t_fdf fdf);
void	draw_line(t_fdf fdf);
void	xy1(t_fdf fdf, int x1, int y1);
void	xy2(t_fdf fdf, int x2, int y2);
void	uprld(int key, t_fdf *fdf);


#endif