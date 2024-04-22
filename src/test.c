#include "../minilibx/mlx.h"

int main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 800, "minilibx");
	for (int y = 100; y < 700; ++y)
	{
		for (int x = 100; x < 700; ++x)
		{
			mlx_pixel_put(mlx, window, x, y, 0xffffff);
		}
	}
	mlx_loop(mlx);
}
