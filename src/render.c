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
		c->x = fract->julia_x;
		c->y = fract->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
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
	z.x = 0.0;
	z.y = 0.0;

	c.x = (map(x, -2, +2, 0, WIDTH) * fract->zoom) + fract->shift_x;
	c.y = (map(y, +2, -2, 0, HEIGHT) * fract->zoom) + fract->shift_y;
	fractol_set(&z, &c, fract);
	while (i < fract->iter )
	{
		z = sum(square(z), c);
		if ((z.x * z.x) + (z.y *z.y) > fract->escape_value)
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
	mlx_put_image_to_window(fract->mlx, fract->window, fract->img.addr, 0, 0);
}
