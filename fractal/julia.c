#include "fractol.h"

static	void	compute_complex_coords(t_fractal *fract, int x, int y, t_coords *coords)
{
	coords->cx = fract->real_min + x * coords->scaled_re;
	coords->cy = fract->imag_min + y * coords->scaled_im;
}

static void	calculate_scaling(t_fractal *fract, t_coords *coords)
{
	coords->scaled_re = (fract->real_max - fract->real_min) / WIDTH;
	coords->scaled_im = (fract->imag_max - fract->imag_min) / HEIGHT;
}

static int julia_iterations(double zx, double zy, t_fractal *fract)
{
    double next_zx;
    double next_zy;
    int iter = 0;
    while (zx * zx + zy * zy <= 4 && iter < fract->max_iter)
    {
        next_zx = zx * zx - zy * zy + fract->c_re;
        next_zy = 2 * zx * zy + fract->c_im;
        zx = next_zx;
        zy = next_zy;
        iter++;
    }
    return iter;
}

void	draw_julia(t_data *data, t_fractal *fract)
{
	int x;
    int y;
    int iter;
    y = 0;
    t_coords coords;
    calculate_scaling(fract, &coords);
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            compute_complex_coords(fract, x, y, &coords);
            iter = julia_iterations(coords.cx, coords.cy, fract);
            ft_pixel_put(data, x, y, get_color(iter, fract->max_iter));
            x++;
        }
        y++;
    }
}
/*
void	draw_julia(t_data *data, t_fractal *fract)
{
	int	x = 0;
	int y = 0;
	int	iter;
	double	zx, zy, next_zx, next_zy;
	double	scaled_real = (fract->real_max - fract->real_min) / WIDTH;
	double	scaled_imag = (fract->imag_max - fract->imag_min) / HEIGHT;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			zx = fract->real_min + x * scaled_real;
			zy = fract->imag_min + y * scaled_imag;
			iter = 0;
			while (zx * zx + zy * zy <= 4 && iter < fract->max_iter)
			{
				next_zx = zx * zx - zy * zy + fract->c_re;
				next_zy = 2 * zx *zy + fract->c_im;
				zx = next_zx;
				zy = next_zy;
				iter++;
			}
			ft_pixel_put(data, x, y, get_color(iter, fract->max_iter));
			x++;
		}
		y++;
	}
}
*/
