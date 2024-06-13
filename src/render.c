#include "fractol.h"

static void	my_pixel_put(int x, int y, t_data *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

static void	fractol_set(t_complex *z, t_complex *c, t_fractol *fract)
{
	if (!ft_strncmp(fract->name, "julia", 5))
	{
		c->r = fract->julia_r;
		c->i = fract->julia_i;
	}
	else
	{
		c->r = z->r;
		c->i = z->i;
	}
}



/*
z = z^2 + c
z starts at 0 ~ (0, 0);
c is the actual point
*/


void	handle_pixel(int x, int y, t_fractol *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	i = 0;
	z.r = (map(x, -2, +2, 0, WIDTH) * fract->zoom) + fract->shift_r;
	z.i = (map(y, +2, -2, 0, HEIGHT) * fract->zoom) + fract->shift_i;
	fractol_set(&z, &c, fract);
	while (i < fract->iter )
	{
		z = sum(square(z), c);
		if ((z.r * z.r) + (z.i *z.i) > fract->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fract->iter)
			my_pixel_put(x, y, &fract->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fract->img, WHITE);
}

void	render_fractol(t_fractol *fract)
{
	int	x;
	int y;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fract);
		}
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.addr, 0, 0);
}
