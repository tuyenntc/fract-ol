#include "fractol.h"

void	draw_mandelbrot(t_data *f)
{
	f->x = 0;
	f->y = 0;
	while (f->x < SIZE)
	{
		while (f->y < SIZE)
		{
			calculate_mandelbrot(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	return (NULL);
}

void	draw_julia(t_data *f)
{
	f->x = 0;
	f->y = 0;
	while (f->x < SIZE)
	{
		while (f->y < SIZE)
		{
			calculate_julia(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
}
