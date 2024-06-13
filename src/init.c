#include "fractol.h"

static void	malloc_error(void)
{
	perror("error memory allocation");
	exit(EXIT_FAILURE);
}

static void	hook_events(t_fractol *fract)
//{
//	mlx_hook(fract->window, 2, 0, handle_key, fract);
//	mlx_hook(fract->window, 4, 0, handle_mouse, fract);
//	mlx_hook(fract->window, 17, 0, handle_exit, fract);
//}
{
	mlx_hook(fract->mlx_win, KeyPress, KeyPressMask, key_handler, fract);
	mlx_hook(fract->mlx_win, ButtonPress, ButtonPressMask, mouse_handler, fract);
	mlx_hook(fract->mlx_win, DestroyNotify, StructureNotifyMask, close_handler, fract);
	mlx_hook(fract->mlx_win, MotionNotify, PointerMotionMask, julia_track, fract);
}


static void	init_data(t_fractol *fract)
{
	fract->escape_value = 4;
	fract->iter = MAX_COUNT;
	fract->shift_r = 0.0;
	fract->shift_i = 0.0;
	fract->zoom = 1.0;
}

static void	create_window(t_fractol *fract)
{
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->name);
	if (!fract->win)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		malloc_error();
	}
}
//mlx_destroy_display() will replace mlx_destroy_window() for linux
static void	create_image(t_fractol *fract)
{
	fract->img.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->img.img)
	{
		mlx_destroy_window(fract->mlx, fract->win);
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		malloc_error();
	}
	fract->img.addr = mlx_get_data_addr(fract->img.addr, 
				&fract->img.bpp,
				&fract->img.line_len,
				&fract->img.endian);
}

void	init_fractol(t_fractol *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		malloc_error();
	create_window(fract);
	create_image(fract);
	hook_events(fract);
	init_data(fract);
//	fract->color = WHITE;
}


