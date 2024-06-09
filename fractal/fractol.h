#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractal
{
	double	real_min;
	double	real_max;
	double	imag_min;
	double	imag_max;
	int		max_iter;
	double	c_re;
	double	c_im;
}	t_fractal;

void	ft_pixel_put(t_data *data, int x, int y, int color);
void	init_fractal(t_fractal *fract, double c_re, double c_im);
int		get_color(int iter, int max_iter);
void	draw_mandelbrot(t_data *data, t_fractal *fract);
void	draw_julia(t_data *data, t_fractal *fract);

#endif
