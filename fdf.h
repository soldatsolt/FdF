#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"

#include <mlx.h>
#include <math.h>

typedef struct	s_img
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*str;
}				t_img;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_img	img;
}				t_fdf;

#endif