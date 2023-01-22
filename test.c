#include <mlx.h>
#include <stdio.h>
#include <math.h>

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
	printf("%f\n", sin(M_PI / 2 - M_PI / 6));
	printf("%f\n", sin(3 * M_PI / 2 - M_PI / 6));
}