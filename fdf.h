/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:18:18 by kmills            #+#    #+#             */
/*   Updated: 2019/04/12 16:11:58 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"

#include <mlx.h>
#include <math.h>

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			colour;
	int			k;
}				t_point;

typedef struct	s_proj
{
	int			f_i;
	int			f_p;
	int			f_3d;
	int			n;
}				t_proj;

typedef struct	s_d3d
{
	float		ox;
	float		oy;
	float		oz;
}				t_d3d;

typedef struct	s_map
{
	t_point		**point;
	int			height;
	int			width;
	int			x;
	int			y;
	int			z;
	int			min;
	int			max;
}				t_map;

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
	int			x;
	int			y;
	int			xx;
	int			yy;
	int			xxx;
	int			yyy;
}				t_img;

typedef struct s_mouse
{
	int			mouse_flag1;
	int			mouse_flag2;
	int			mouse_x;
	int			mouse_y;
}				t_mouse;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			zoom;
	t_img		img;
	t_mkline	*koord;
	t_map		map;
	t_mouse		mouse;
	t_proj		proj;
	t_d3d		d3d;

}				t_fdf;

int	get_color(int error2, int *ds, t_mkline example, int x, int y, int colour1, int colour2);
int	map_maker(char *str, t_fdf *fdf, int y_count);
int     valid(char *str);
void	*img_ptr;
int	deal_key(int key, t_fdf *fdf);
int	expose_hook(void *param);
int	deal_mouse(int mouse, int x, int y, t_fdf *fdf);
void	whitepixel(t_fdf fdf, int x, int y, int colour);
int	*deltaandsign(t_fdf fdf);
void	draw_line(t_fdf fdf, int colour1, int colour2);
void	xy1(t_fdf fdf, int x1, int y1);
void	xy2(t_fdf fdf, int x2, int y2);
void	uprld(int key, t_fdf *fdf);
void	make1stgrid(t_fdf *ffdf);
t_point	dimension3(t_point dot, float qx, float qz);
void	makefongray(t_fdf fdf);

#endif
