/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:12:21 by cpapot            #+#    #+#             */
/*   Updated: 2023/09/27 13:32:46 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "close.h"

int	clean_minirt_data(t_data *data_pt)
{
	if (data_pt->ambient_light != NULL)
		free(data_pt->ambient_light);
	if (data_pt->camera != NULL)
		free(data_pt->camera);
	if (data_pt->lights_arr != NULL)
		free(data_pt->lights_arr);
	if (data_pt->sphere_arr != NULL)
		free(data_pt->sphere_arr);
	if (data_pt->plane_arr != NULL)
		free(data_pt->plane_arr);
	if (data_pt->cylinder_arr != NULL)
		free(data_pt->cylinder_arr);
	if (data_pt->cone_arr != NULL)
		free(data_pt->cone_arr);
	if (data_pt->disk_arr != NULL)
		free(data_pt->disk_arr);
	return (1);
}

void	destroy_image_arr(t_mlx_info *win, t_data *data)
{
	int	index;

	index = 0;
	while (index != (int)data->ca_nb)
	{
		(void)mlx_destroy_image(win->mlx_ptr, win->img_arr[index].img);
		index++;
	}
	free(win->img_arr);
}

void	close_minirt(t_mlx_info *win, t_data *data, int status)
{
	destroy_image_arr(win, data);
	clean_minirt_data(data);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
	exit(status);
}
