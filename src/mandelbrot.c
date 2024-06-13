#include "fractol.h"

/*
	draw_mandelbrot: Iterates through each row (y) and calls draw_mandelbrot_row.
	draw_mandelbrot_row: Iterates through each column (x) in the row and calls 
		draw_mandelbrot_pixel to handle the computation for each pixel.
	draw_mandelbrot_pixel: Computes the complex coordinates (cx, cy) for the pixel 
		and calculates the number of iterations using compute_mandelbrot_iter. It then puts the pixel on the image.
	compute_mandelbrot_iter: Calculates the number of iterations for the Mandelbrot set 
		escape time algorithm. It calls update_z_values to update zx and zy in each iteration.
	update_z_values: Updates the values of zx and zy based on the Mandelbrot set formula.

void	draw_mandelbrot(t_data *data, t_fractol *fract)
{
	int y = 0;
    while (y < HEIGHT)
    {
        draw_mandelbrot_row(data, fract, y);
        y++;
    }
}

void	draw_mandelbrot_row(t_data *data, t_fractol *fract, int y)
{
	int x = 0;
    double scaled_real = (fract->real_max - fract->real_min) / WIDTH;
    double scaled_imag = (fract->imag_max - fract->imag_min) / HEIGHT;

    while (x < WIDTH)
    {
        draw_mandelbrot_pixel(data, fract, x, y, scaled_real, scaled_imag);
        x++;
    }
}

void	draw_mandelbrot_pixel(t_data *data, t_fractol *fract, int x, int y, double scaled_real, double scaled_imag
{
	double cx = fract->real_min + x * scaled_real;
    double cy = fract->imag_min + y * scaled_imag;
    int iter = compute_mandelbrot_iter(cx, cy, fract);
    ft_pixel_put(data, x, y, get_color(iter, fract->max_iter));
}

int	compute_mandelbrot_iteration(double cx, double cy, t_fractol *fract)
{
	double	zx = 0.0;
	double	zy = 0.0;
	int iteration = 0;
	double	zx2 = zx * zx;
	double	zy2 = zy * zy;
	while (zx2 + zy2 <= 4 && iteration < fract->iter)
	{
		iteration++;
		update_z_values(&zx, &zy, cx, cy);
		zx2 = zx * zx;
		zy2 = zy * zy;
	}
	return (iteration);
}

void	update_z_values(double *zx, double *zy, double cx, double cy)
{
	double next_zx;
	double	next_zy;
	next_zx = (*zx * *zx) - (*zy * *zy) + cx;
	next_zy = 2 * (*zx) * (*zy) + cy;
	*zx = next_zx;
	*zy = next_zy;
}
*/
void	draw_mandelbrot(t_data *data, t_fractol *fract)
{
	int y;
	y = 0;
	while (y < HEIGHT)
	{
		draw_mandelbrot(data, fract, y);
		y++;
	}
}

void	draw_mandelbrot(t_data *data, t_fractol *fract, int y)
{
	int x;
	double	scaled_real;
	double	scaled_imag;
	x = 0;
	scaled_real = (fract->real_max - fract->real_min) / WIDTH;
	scaled_imag = (fract->imag_max - fract->imag_min) / HEIGHT;
	while (x < WIDTH)
	{
		fract->cx = fract->real_min + x * scaled_real;
		fract->cy = fract->imag_min + y * scaled_imag;
		fract->iter = compute_mandelbrot_iter(fract->cx, fract->cy, fract);
		ft_pixel_put(data, x, y, get_color(fract->iter, fract->max_iter));
	}

}
