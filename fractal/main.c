#include "fractol.h"
void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iter, int max_iter)
{
	if (iter == max_iter)
		return (0x00000000);
	return ((int)(0x00FFFFFF * ((double)iter/ max_iter)));
}

int key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

void	init_fractal(t_fractal *fract)
{
	fract->real_min = -2.0;
	fract->real_max = 2.0;
	fract->imag_min = -2.0;
	fract->imag_max = 2.0;
	fract->max_iter = MAX_ITER;
	fract->c_re = -0.7;
	fract->c_im = 0.27015;
}

int	main(int ac, char **av)
{
	t_data	data;
	t_fractal fract;
	if (ac != 2 || (strcmp(av[1], "mandelbrot") != 0 && strcmp(av[1], "julia") != 0))
	{
		printf("usage: %s [mandelbrot/julia]\n", av[0]);
		return (1);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	init_fractal(&fract);
	if (strcmp(av[1], "mandelbrot") == 0)
		draw_mandelbrot(&data, &fract);
	else if (strcmp(av[1], "julia") == 0)
		draw_julia(&data, &fract);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
