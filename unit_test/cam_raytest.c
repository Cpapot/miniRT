#include "../srcs/parsing/structures.h"
#include "../inc/miniRT.h"
#include "../inc/window.h"

static double	mapping_Xcoord(int pixel_pos, int xsize, int ysize, double fov)
{
	double	result;
	double	ratio;
	double	scale;

	scale = tan(fov / 2.0 * M_PI / 180);
	ratio = (double)xsize / (double)ysize;
	result = ((double)pixel_pos + 0.5) / ((double)xsize);
	result = (2 * result - 1) * ratio * scale;
	return (result);
}

static double	mapping_Ycoord(int pixel_pos, int screen_size, double fov)
{
	double	result;
	double	scale;

	scale = tan(fov / 2.0 * M_PI / 180);
	result = ((double)pixel_pos + 0.5) / ((double)screen_size);
	result = (2 * result - 1) * scale;
	return (result);
}

static t_vec_3	compute_direction(t_vec_3 cam_vector, t_vec_3 ray_dir)
{
	t_vec_3	result;
	t_vec_3	x;
	t_vec_3	y;

	if (cam_vector.y == 1 || cam_vector.y == -1)
		x = set_vec(cam_vector.y, 0, 0);
	else
		x = scalar_product(set_vec(0, 1, 0), cam_vector);
	y = scalar_product(cam_vector, x);
	result.x = ray_dir.x * x.x + ray_dir.y * y.x + ray_dir.z * cam_vector.x;
	result.y = ray_dir.x * x.y + ray_dir.y * y.y + ray_dir.z * cam_vector.y;
	result.z = ray_dir.x * x.z + ray_dir.y * y.z + ray_dir.z * cam_vector.z;
	return (result);
}

//dois renvoyer un vecteur pour chaque pixel de la fenetre (en gros on passe de la 2d a la 3d)
t_ray	find_camray(t_camera cam_info, int x, int y)
{
	t_vec_3	ray_dir;
	t_ray	cam_ray;

	cam_ray.origin = cam_info.origin;
	ray_dir.x = mapping_Xcoord(x, XSIZE, YSIZE, cam_info.fov);
	ray_dir.y = mapping_Ycoord(y, YSIZE, cam_info.fov);
	ray_dir.z = 1;
	normalize_vec(&ray_dir);
	cam_ray.direction = compute_direction(cam_info.vector, ray_dir);
	return (cam_ray);
}

int main()
{
    t_camera cam_info;
    cam_info.origin.x = 0;
	cam_info.origin.y = 0;
	cam_info.origin.z = 10;// Exemple de coordonnées de l'origine de la caméra
    cam_info.vector = set_vec(-0.754, 0.5, -1.5); // Exemple de vecteur direction de la caméra
    cam_info.fov = 90; // Exemple d'angle de champ de vision de la caméra

    int xsize = XSIZE; // Exemple de taille horizontale de la fenêtre
    int ysize = YSIZE; // Exemple de taille verticale de la fenêtre

    for (int y = 0; y < ysize; y++)
    {
        for (int x = 0; x < xsize; x++)
        {
            t_ray cam_ray = find_camray(cam_info, x, y);
			if ((x == 0 && y == 0) || (y == YSIZE - 1 && x == XSIZE - 1) || (y == YSIZE - 1 && x == 0)
				|| (x == XSIZE - 1 && y == 0) || (x == XSIZE / 2 && y == YSIZE / 2))
			{
				printf("Pixel (%d, %d): Origin (%f, %f, %f), Direction (%f, %f, %f)\n",
					x, y,
					cam_ray.origin.x, cam_ray.origin.y, cam_ray.origin.z,
					cam_ray.direction.x, cam_ray.direction.y, cam_ray.direction.z);
			}
        }
    }

    return 0;
}

//gcc unit_test/test_camray.c srcs/vec3_utils.c -lm
