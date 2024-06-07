#include "fractol.h"

/*
* ./fractol mandelbrot
* ./fractol julia <real> <img>: (-0.4, 0.3); (-0.735, -0.213);....
*/


int	main(int ac, char **av)
{
	t_fractol	fract;
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", ft_strlen("mandelbrot") + 1))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", ft_strlen("julia") + 1)))
	{
		fract.name = av[1];
		init_fractol(&fract);
		render_fractol(&fract);
		mlx_loop(fract.mlx);
		return (0);
	}


//	{
//		instruction();
//		fract.name = av[1];
//		if (!ft_strncmp(fract.name, "julia", 5))
//		{
//			fract.julia_x = atodbl(av[2]);
//			fract.julia_y = atodbl(av[3]);
//		}
//		init_fractol(&fract);
//		render_fractol(&fract);
//		mlx_loop(fract.mlx);
//		return (0);
//	}
	else
	{
		ft_putstr_fd(ERR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
