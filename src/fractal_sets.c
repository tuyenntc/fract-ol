#include "fractol.h"

void	calculate_mandelbrot(t_data *f)
{
	int		i;
	double	x_tmp;

	f->set = "mandelbrot"
	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (f->x / f->zoom) + f->offset_x;
	f->cy = (f->y / f->zoom) + f->offset_y;
	while (++i <f->max_iter)
	{
		x_tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2. * f->zx * f->zy + f->cy;
		f->zx = x_tmp;
		if (f->zx * f->zx + f->zy * f->zy >= DBL_MAX)
			break;
	}
	if (i == f->max_iter)
		color_pixel(f, f->x, f->y, 0x000000);
	else
		color_pixel(f, f->x, f->y, (f->color * i));
}


void	calculate_julia(t_data *f)
{
	int		i;
	double	tmp;
	f->set = "julia";
	f->zx = f->x / f->zoom + f->offset_x;
	f->zy = f->y / f->zoom + f->offset_y;
	i = 0;
	while (++i < f->max_iter)
	{
		tmp = f->zx;
		f->zx = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2 * f->zy * tmp + f->cy;
		if (f->zx * f->zx + f->zy * f->zy >= DBL_MAX)
			break;
	}
	if (i == f->max_iter)
		color_pixel(f, f->x, f->y, 0x000000);
	else
		color_pixel(f, f->x, f->y, (f->color * (i % 255)));
}
