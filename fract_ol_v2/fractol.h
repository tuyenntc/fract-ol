#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "../minilibx/mlx.h"

# include "../ft_printf/ft_printf.h"
# include <math.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/X.h>
//Window dimensions
# define WIDTH	1000
# define HEIGHT	1000

//Colours
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define MAGENTA		0xFF00FF
# define LIME			0xCCFF00
# define ORANGE			0xFF6600
# define PURPLE			0x9932CC
# define AQUA			0x33CCCC
# define PINK			0xFF66B2
# define ELECTRIC		0x0066FF
# define LIGHTENING		0x00CCFF
# define LAVA			0xFF3300
# define YELLOW			0xFFFF00
# define PASTELYELLOW	0xFFFF99
# define	PASTELPINK	0xFFB6C1


typedef struct s_fractol
{
	char		*title;
	void		*mlx_connect;
	void		*window;
	void		*img;
	char		*img_addr;
	int			img_bpp;
	int			img_line;
	int			img_endian;
	double		cmplx_r;
	double		cmplx_i;
	double		hypotenuse;
	double		escape_point;
	int			iterations;
	double		shift_r;
	double		shift_i;
	double		zoom;
	int			current_colour;
	double		julia_r;
	double		julia_i;
}	t_fractol;

typedef struct s_map_coords
{
	double		unscaled_num;
	double		new_min;
	double		new_max;
	double		old_min;
	double		old_max;
}	t_map_coords;

void		fractol_init(t_fractol *fract);

//Render
void		fractol_render(t_fractol *fract);
int 		blend_colours(int colour1, int colour2, double t);
void		colour_shift(t_fractol *fract);

//Events handling
int			handle_key(int keysym, t_fractol *fract);
int			handle_mouse(int button, int x, int y, t_fractol *fract);
int			clean_exit(t_fractol *fract);
void		instructions();

//Utils
double		map(t_map_coords coords);
void get_complex_map(int x, int y, t_fractol *fract);
t_fractol	sum_complex(t_fractol z1, t_fractol z2);
t_fractol	square_complex(t_fractol z);
void		malloc_error();
double		atodbl(char *s);
int ft_strncmp(char *s1, char *s2, int n);
void		zoom_in(t_fractol *fract, double mouse_r, double mouse_i);
void		zoom_out(t_fractol *fract, double mouse_r, double mouse_i);



#endif
