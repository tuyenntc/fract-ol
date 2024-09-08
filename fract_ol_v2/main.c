#include "fractol.h"
/*
int	main(int argc, char **argv)
{
	t_fractol	fract;
	
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		|| (argc == 4 &&!ft_strncmp(argv[1], "julia", 6)))
	{
		instructions();
		fract.title = argv[1];
		if (!ft_strncmp(fract.title, "julia", 5))
		{
			fract.julia_r = atodbl(argv[2]);
			fract.julia_i = atodbl(argv[3]); 
		}
		if (fract.julia_r > 2.0 || fract.julia_r < -2.0)
			ft_printf("valid values belong to range -2.0 - 2.0\n");
		if (fract,julia_i > 2.0 || fract.julia_i < -2.0)
			ft_printf("valid values belong to range -2.0 - 2.0\n");
		fractol_init(&fract);
		fractol_render(&fract);
		mlx_loop(fract.mlx_connect);
		return (0);
	}
	ft_printf("Invalid input\n");
	ft_printf("Try:\n<./fractol mandelbrot> or\n<./fractol julia -0.4 +0.6> or\n<./fractol julia -0.835 -0.2321>\n");
	exit(EXIT_FAILURE);
}
*/

int main(int ac, char **av)
{
	t_fractol   fract;
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
	{
		instructions();
        fract.title = av[1];
        fractol_init(&fract);
        fractol_render(&fract);
        mlx_loop(fract.mlx_connect);
        return (0);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 6))
	{
		instructions();
        fract.title = av[1];
        fract.julia_r = atodbl(av[2]);
        fract.julia_i = atodbl(av[3]);
		if ((fract.julia_r || fract.julia_i) > 2.0 || (fract.julia_r || fract.julia_i) < -2.0)
		{
			ft_printf("valid values belong to range -2.0 - 2.0\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			fractol_init(&fract);
       		fractol_render(&fract);
        	mlx_loop(fract.mlx_connect);
        }
		return (0);
	}
	else
	{
		ft_printf("invalid input\n");
		ft_printf("Try:\n<./fractol mandelbrot> or\n<./fractol julia -0.4 +0.6> or\n<./fractol julia -0.835 -0.2321>\n");
		exit(EXIT_FAILURE);
	}
}
