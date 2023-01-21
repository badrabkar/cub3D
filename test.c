#include <mlx.h>
#include <stdio.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	int	width = 60;
	int	height = 60;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_xpm_file_to_image(mlx, "./textures/bluestone.xpm", &width, &height);
	img.addr = mlx_get_img_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("%s\n", img.addr);
	printf("bits per pixel : %d\n", img.bits_per_pixel);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}