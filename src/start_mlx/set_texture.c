/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:56:30 by olly              #+#    #+#             */
/*   Updated: 2025/02/03 16:35:17 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_texture(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return ;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HIGHT,
			"O&A Dynamics");
	if (!mlx->win_ptr)
		return (clean_mlx(mlx));
	if (create_placeholder_image(mlx->mlx_ptr, &mlx->image[PLACEHOLDER]))
		return (clean_mlx(mlx));
	if (upload_texture(mlx->mlx_ptr, mlx->map->north_texture,
			&mlx->image[WALL_NORTH]))
		return (clean_mlx(mlx));
	if (upload_texture(mlx->mlx_ptr, mlx->map->south_texture,
			&mlx->image[WALL_SOUTH]))
		return (clean_mlx(mlx));
	if (upload_texture(mlx->mlx_ptr, mlx->map->west_texture,
			&mlx->image[WALL_WEST]))
		return (clean_mlx(mlx));
	if (upload_texture(mlx->mlx_ptr, mlx->map->east_texture,
			&mlx->image[WALL_EAST]))
		return (clean_mlx(mlx));
}

int	upload_texture(void *mlx_ptr, char *txt_name, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx_ptr, txt_name, &img->width,
			&img->height);
	if (!img->img)
		return (EXIT_FAILURE);
	img->address = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (EXIT_SUCCESS);
}

int	create_placeholder_image(void *mlx_ptr, t_img *img)
{
	img->img = mlx_new_image(mlx_ptr, SCREEN_WIDTH, SCREEN_HIGHT);
	if (!img->img)
		return (EXIT_FAILURE);
	img->address = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->width = SCREEN_WIDTH;
	img->height = SCREEN_HIGHT;
	return (EXIT_SUCCESS);
}
