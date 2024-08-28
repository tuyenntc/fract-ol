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
	if (keycode == 53)// ESC key 53 on MAC
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}
/*
int key_hook(int keycode, t_data *data)
{
    if (keycode == 65307) // ESC key on Linux
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return (0);
}
*/


int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	t_fractal *fract = data->fractal;
	double	zoom_factor = 1.1;
	double	mouse_re = fract->real_min + (double)x / WIDTH * (fract->real_max - fract->real_min);
	double	mouse_im = fract->imag_min + (double)y / HEIGHT * (fract->imag_max - fract->imag_min);
	if (button == 4)//scroll up
	{
		fract->real_min = mouse_re + (fract->real_min - mouse_re) / zoom_factor;
		fract->real_max = mouse_re + (fract->real_max - mouse_re) / zoom_factor;
		fract->imag_min = mouse_im + (fract->imag_min - mouse_im) / zoom_factor;
		fract->imag_max = mouse_im + (fract->imag_max - mouse_im) / zoom_factor;
	}
	if (button == 5)//scroll down
	{
		fract->real_min = mouse_re + (fract->real_min - mouse_re) * zoom_factor;
		fract->real_max = mouse_re + (fract->real_max - mouse_re) * zoom_factor;
		fract->imag_min = mouse_im + (fract->imag_min - mouse_im) * zoom_factor;
		fract->imag_max = mouse_im + (fract->imag_max - mouse_im) * zoom_factor;
	}
	mlx_clear_window(data->mlx, data->win);
	if (strcmp(data->fractal_type, "mandelbrot") == 0)
		draw_mandelbrot(data, fract);
	if (strcmp(data->fractal_type, "julia") == 0)
		draw_julia(data, fract);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}


void	init_fractal(t_fractal *fract, double c_re, double c_im)
{
	fract->real_min = -2.0;
	fract->real_max = 2.0;
	fract->imag_min = -2.0;
	fract->imag_max = 2.0;
	fract->max_iter = MAX_ITER;
	fract->c_re = c_re;
	fract->c_im = c_im;
}


int validate_arguments(int ac, char **av)
{
	(void)av;
	if (ac < 2)
//	{
//		ft_putstr_fd(HELP_MSG, STDERR_FILENO);
//		return (1);
//	}
	{
		ft_printf("usage: \n");
		ft_printf("./fractol mandelbrot\n");
		ft_printf("./fractol julia <x_value> <y_value>\n");
		return (1);
	}
	return (0);
}

void	initialize_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}

int	select_fractal(int ac, char **av, t_fractal *fract, t_data *data)
{
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		init_fractal(fract, 0, 0);
		draw_mandelbrot(data, fract);
	}
	else if 
		(ft_strncmp(av[1], "julia", 5) == 0)
		{
			if (ac != 4)
			{
				ft_putstr_fd(HELP_MSG, STDERR_FILENO);
				return (1);
			}
			double c_re = atodbl(av[2]);
			double c_im = atodbl(av[3]);
			init_fractal(fract, c_re, c_im);
			draw_julia(data, fract);
		}
		return (0);
}
void	setup_hooks(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, 17, 0, close_window, data);
}
/*
void setup_hooks(t_data *data)
{
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    mlx_key_hook(data->win, key_hook, data);
    mlx_mouse_hook(data->win, mouse_hook, data);
    mlx_hook(data->win, 17, 0, close_window, data);
}
*/

int main(int ac, char **av)
{
	t_data data;
	t_fractal fract;
	if (validate_arguments(ac, av))
		return (1);
	initialize_data(&data);
	data.fractal = &fract;
	if (select_fractal(ac, av, &fract, &data))
		return (1);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
/*
int	main(int ac, char **av)
{
	t_data	data;
	t_fractal fract;
//	if (ac != 2 || (strcmp(av[1], "mandelbrot") != 0 && strcmp(av[1], "julia") != 0))
	if (ac < 2)
	{
		printf("usage:\n");
		printf("%s mandelbrot\n", av[0]);
		printf("%s julia <c_real> <c_imaginary>\n", av[0]);
		return (1);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	data.fractal = &fract;
	if (strcmp(av[1], "mandelbrot") == 0)
	{
		init_fractal(&fract, 0, 0);
		draw_mandelbrot(&data, &fract);
	} else if (strcmp(av[1], "julia") == 0)
	{
		if (ac != 4)
		{
			printf("usage: %s julia <c_real> <c_imaginary>\n", av[0]);
			return (1);
		}
		double c_re = atof(av[2]);
		double c_im = atof(av[3]);
		init_fractal(&fract, c_re, c_im);
		draw_julia(&data, &fract);
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
*/
