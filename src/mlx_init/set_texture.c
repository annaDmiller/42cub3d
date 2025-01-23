/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olly <olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:56:30 by olly              #+#    #+#             */
/*   Updated: 2025/01/23 17:09:59 by olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void set_texture(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return ;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "O&A Dynamics");
	if (!mlx->win_ptr)
        clean_mlx(mlx);
	if (!mlx->win_ptr)
		return (clean_mlx(mlx));
	if (create_placeholder_image(mlx->mlx_ptr, mlx->image[PLACEHOLDER]))
		return (clean_mlx(mlx));
	if (upload_texture(mlx->mlx_ptr, mlx->data->north_texture, mlx->image[WALL_NORTH]))
		return (clean_mlx(mlx));
	if (upload_texture(mlx->mlx_ptr, mlx->data->south_texture, mlx->image[WALL_SOUTH]))
		return (clean_mlx(mlx));
	if (upload_texture(mlx->mlx_ptr, mlx->data->west_texture, mlx->image[WALL_WEST]))
		return (clean_mlx(mlx));
	if (upload_texture(mlx->mlx_ptr, mlx->data->east_texture, mlx->image[WALL_EAST]))
		return (clean_mlx(mlx));
}

// Creates a blank image in memory and retrieves its address for use in rendering

int	create_placeholder_image(void *mlx_ptr, t_img *img)
{
	img->img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT); // SEGFAULT IN THIS LINE TO CHECK
	if (!img->img)
		return (EXIT_FAILURE);
	img->address = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	img->width = WIDTH;
	img->height = HEIGHT;
	return (EXIT_SUCCESS);
}


// loads actual textures for walls (north, south, west, east) from .xpm files

int	upload_texture(void *mlx_ptr, char *texture, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx_ptr, texture, &img->width, &img->height);
	if (!img->img)
		return (EXIT_FAILURE);
	img->address = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (EXIT_SUCCESS);
}