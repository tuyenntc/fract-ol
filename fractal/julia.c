#include "fractol.h"

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
