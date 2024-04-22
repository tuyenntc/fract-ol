#include "fractol.h"

void	color_pixel(t_data *f, int x, int y, int color)
{

}

int	exit_fractal(t_data *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->window);
	free(f->mlx);
	free(f);
	exit(1);
	return (0);
}


double	generate_complex_nb(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}


void	change_iter(t_data *f, int key_code)
{
	if (key_code == M)
	{
		if (f->max_iter > 50)
			f->max_iter -= 50;
	}
	else if (key_code == P)
	{
		if (f>max_iter < 1000)
			f->max_iter +=50;
	}
}
