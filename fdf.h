/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:18:18 by kmills            #+#    #+#             */
/*   Updated: 2019/04/12 23:55:32 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			colour;
	int			k;
	int			kz;
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

typedef struct	s_mouse
{
	int			mouse_flag1;
	int			mouse_flag2;
	int			mouse_x;
	int			mouse_y;
}				t_mouse;

typedef struct	s_fdf
{
	float		nm;
	float		nb;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			zoom;
	int			buttons[4];
	t_img		img;
	t_mkline	*koord;
	t_map		map;
	t_mouse		mouse;
	t_proj		proj;
	t_d3d		d3d;

}				t_fdf;

void			var_in_map(t_fdf *fdf, char **num, int y);
t_point			rec_col(t_mkline koord, int colour1, int colour2);
int				receive_colour(char *str);
int				get_init_colour(t_map map, int colour1, int colour2, int z);
int				find_min_max(int value, int flag);
double			percent(int start, int end, int current);
int				get_light(int start, int end, double percentage);
int				get_color(int *ds, int x, int y, t_point col);
int				map_maker(char *str, t_fdf *fdf, int y_count);
int				valid(char *str);
int				deal_key(int key, t_fdf *fdf);
int				expose_hook(void *param);
int				deal_mouse(int mouse, int x, int y, t_fdf *fdf);
void			whitepixel(t_fdf fdf, int x, int y, int colour);
int				*deltaandsign(t_fdf fdf);
void			draw_line(t_fdf fdf, int colour1, int colour2);
void			xy1(t_fdf fdf, int x1, int y1);
void			xy2(t_fdf fdf, int x2, int y2);
void			uprld(int key, t_fdf *fdf);
void			make1stgrid(t_fdf *ffdf);
t_point			dimension3(t_point dot, float qx, float qz);
void			makefongray(t_fdf fdf);
void			uvel_z(t_fdf *ffdf, int i, int j);
void			umen_z(t_fdf *ffdf, int i, int j);
t_fdf			*zero_buttons(t_fdf *fdf);
void			err_map(void);
int				raduga(t_point *dot);
void			makefongray(t_fdf fdf);
void			if1indraw_line(int *error, int *ds, t_fdf *fdf);
void			if2indraw_line(int *error, int *ds, t_fdf *fdf);
int				mouse_release(int button, int x, int y, t_fdf *fdf);
int				mouse_move(int x, int y, t_fdf *fdf);

#endif
