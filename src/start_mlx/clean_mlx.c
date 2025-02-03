/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:57:15 by olly              #+#    #+#             */
/*   Updated: 2025/02/03 16:35:08 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_mlx(t_mlx *mlx)
{
	destroy_texture(mlx);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->ray);
	clean_data(&mlx->map);
	free(mlx->mlx_ptr);
}

void	destroy_texture(t_mlx *mlx)
{
	if (mlx->image[PLACEHOLDER].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image[PLACEHOLDER].img);
	if (mlx->image[WALL_NORTH].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image[WALL_NORTH].img);
	if (mlx->image[WALL_SOUTH].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image[WALL_SOUTH].img);
	if (mlx->image[WALL_WEST].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image[WALL_WEST].img);
	if (mlx->image[WALL_EAST].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image[WALL_EAST].img);
}

void	clean_mlx_data_fd_exit(t_data **data, void *mlx, int *fd, char *msg)
{
	mlx_destroy_display(mlx);
	close_all_textures(fd);
	clean_data_map_exit(data, 0, msg);
}
