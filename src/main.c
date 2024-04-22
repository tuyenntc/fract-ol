#include "fractol.h"


void	init_fractal(t_data *f)
{
	f->x = 0;
	f->y = 0;
	f->color = 0xffffff;
	f->zoom = 200;
	f->offset_x = -1.21;
	f->offset_y = -1.21;
	f->max_iter = 50;
}

void	init_mlx(t_data *f)
{
	f->mlx = mlx_init();
	f->window = mlx_new_window(f->mlx, SIZE, SIZE, f->set);
	f->img = mlx_new_image(f->mlx, SIZE, SIZE);
	f->img_ptr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_len, &f->endian)
}

int	draw_fractal(t_data *f, char *input)
{
	if (ft_strncmp(input, "mandelbrot", 11) == 0)
		draw_mandelbrot(f);
	else if (ft_strncmp(input, "julia", 6) == 0)
		if (!f->cx && !f->cy)
		{
			f->cx = -0.3244;
			f->cy = 0.05;
		}
		draw_julia(f);
		else
		{
			ft_putendl_fd("available sets: mandelbrot, julia", 1);
			exit_fractal(f);
		}
		mlx_put_image_to_window(f->mlx, f->window, f->img, 0, 0);
		return (0);
}



int	main(int ac, char **av)
{
	t_data	*f;
	if (ac != 2)
	{
		ft_putendl_fd("type: ./fractol <set>", 1);
		ft_putendl_fd("available sets: mandelbrot, julia", 1);
		return (0);
	}
	f = malloc(sizeof(t_data));
	if (f == NULL)
		malloc_error();
	init_fractal(f);
	init_mlx(f);
	mlx_key_hook(f->window, key_hook, f);
	mlx_mouse_hook(f->window, mouse_hook, f);
	mlx_hook(f->window, 17, 0L, exit_fractal, f);
	draw_fractal(f, av[1]);
	mlx_loop(f->mlx);
	return (0);
}
