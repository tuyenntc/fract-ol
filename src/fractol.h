#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "../minilibx/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_COUNT 100
# define ERR_MSG "input: \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define MAGENTA 0xFF00FF
# define LIME 0xCCFF00
# define ORANGE 0xFF6600
# define PURPLE 0x9932CC
# define AQUA 0x33CCCC
# define PINK 0xFF66B2
# define ELECTRIC 0x0066FF
# define LIGHTENING 0x00CCFF
# define LAVA 0xFF3300
# define YELLOW 0xFFFF00
# define PASTELYELLOW 0xFFFF99
# define PASTELPINK 0xFFB6C1


# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define ESC_KEY 53
# define MOUSE_UP 4
# define MOUSE_DOWN 5


typedef struct	s_complex
{
	double	x;//real
	double	y;//img
}	t_complex;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_data;

typedef struct s_fractol
{
	char	*name;
	void	*mlx;
	void	*window;
	t_data	img;

	double	escape_value;
	int		iter;
	double	shift_x;
	double	shift_y;
	double	zoom;
//	int		color;
	double	julia_x;
	double	julia_y;


}	t_fractol;


typedef	struct s_scaling_range
{
	double	min;
	double	max;
}	t_range;

size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
int 		ft_strncmp(char *s1, char *s2, int n);

void		init_fractol(t_fractol *fract);
void		render_fractol(t_fractol *fract);

int			blend_color(int color1, int color2, double t);
void		shift_color(t_fractol *fract);

double		scaling_range(t_scaling points);
double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum(t_complex z1, t_complex z2);
t_complex	square(t_complex z);

//void		zoom_in(t_fractol *fract, double mouse_r, double mouse_i);
//void		zoom_out(t_fractol *frac, double mouse_r, double mouse_i);
void		instruction(void);
int			handle_mouse(int btn, int x, int y, t_fractol *fract);
int			handle_key(int key, t_fractol *fract);
void		error(void);
int 		handle_exit(t_fractol *fract);
double		atodl(char *s);


#endif
