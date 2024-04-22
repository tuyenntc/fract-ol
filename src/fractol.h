#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "../minilibx/mlx.h"

# define SIZE 800
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define ESC_KEY 53
# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct s_data
{
	char	*set;

	void	*mlx;
	void	*window;
	void	*img;
	void	*img_ptr;
	char	*addr;

	int		endian;
	int		line_len;
	int		bits_per_pixel;

	int		x;
	int		y;

	double	cx;
	double	cy;
	double	zx;
	double	zy;
	double	offset_x;
	double	offse_y;
	double	zoom;
	int		color;
	int		max_iter;


}	t_data;

size_t	ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);
int ft_strncmp(const char *s1, const char *s2, size_t n);




#endif
