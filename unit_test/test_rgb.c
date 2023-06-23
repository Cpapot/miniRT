#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int32_t	ft_color(int r, int g, int b, int T)
{
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (T << 24 | r << 16 | g << 8 | b << 0);
}

int	main()
{
	int	r = 0;
	int	g = 0;
	int	b = 0;
	int32_t color = ft_color(12, 14, 55, 1);

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	printf("r :%d g: %d b: %d color %d", r, g, b, color);
}
