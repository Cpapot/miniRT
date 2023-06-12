#include <stdio.h>

double	mapping_Xcoord(int pixel_pos, int screen_size, double ratio)
{
	double	result;

	result = ((double)pixel_pos + 0.5) / ((double)screen_size);
	result = (2 * result - 1) * ratio;
	return (result);
}

double	mapping_Ycoord(int pixel_pos, int screen_size)
{
	double	result;

	result = ((double)pixel_pos + 0.5) / ((double)screen_size);
	result = 2 * result - 1;
	return (result);
}

int main()
{
    int window_width = 1280;
    int window_height = 720;

    for (int y = 0; y < window_height; y++)
    {
        for (int x = 0; x < window_width; x++)
        {
            double mapped_x = mapping_Xcoord(x, window_width, (double)window_width / (double)window_height);
            double mapped_y = mapping_Ycoord(y, window_height);

            printf("Pixel (%d, %d) : Mapped coordinates (%f, %f)\n", x, y, mapped_x, mapped_y);
        }
    }

    return 0;
}
