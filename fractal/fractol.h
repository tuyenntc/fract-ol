#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define HELP_MSG "input: \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
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


typedef struct	s_coords
{
	double	scaled_re;
	double	scaled_im;
	double	cx;
	double	cy;
}	t_coords;
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*fractal_type;
	t_fractal	*fractal;
}	t_data;

int validate_arguments(int ac, char **av);
void initialize_data(t_data *data);
int select_fractal(int ac, char **av, t_fractal *fract, t_data *data);

void    setup_hooks(t_data *data);
void	ft_pixel_put(t_data *data, int x, int y, int color);
void	init_fractal(t_fractal *fract, double c_re, double c_im);
int		get_color(int iter, int max_iter);
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);

void	draw_mandelbrot(t_data *data, t_fractal *fract);
void	draw_julia(t_data *data, t_fractal *fract);

void    ft_putstr_fd(char *s, int fd);
int     ft_strncmp(char *s1, char *s2, int n);
double  atodbl(char *s);
#endif
