#include "../minilibx/mlx.h"

#define WIDTH 300
#define HEIGHT 300
#define MAX_COUNT 300

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

/*
int	main(void)
{
	void	*mlx_connect;
	void	*mlx_window;
	mlx_connect = mlx_init();
	mlx_window = mlx_new_window(mlx_connect, WIDTH, HEIGHT, "Bolloc painting");
	for (int y = HEIGHT * 0.1; y < HEIGHT * 0.9; ++y)
	{
		for (int x = WIDTH * 0.1; x < WIDTH 0.9; ++x)
		{
			mlx_pixel_put(mlx_connect, mlx_window, x, y, 0xffffff);
		}
	}
	mlx_loop(mlx_connect);
}
*/
/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
int	main(void)
{
	void	*mlx_connect;
	void	*mlx_window;
	t_data	img;
	mlx_connect = mlx_init();
	mlx_window = (mlx_new_window(mlx_connect, WIDTH, HEIGHT, "hello"));
	img.img = mlx_new_image(mlx_connect, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0xffffff);
	mlx_put_image_to_window(mlx_connect, mlx_window, img.img, 0, 0);
	mlx_loop(mlx_connect);
}
*/


