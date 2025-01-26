/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olly <olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:57:15 by olly              #+#    #+#             */
/*   Updated: 2025/01/26 12:58:16 by olly             ###   ########.fr       */
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
	clean_data(&mlx->map);
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
	/* if (mlx->image[FLOOR_IMG].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image[FLOOR_IMG].img);
	if (mlx->image[CEILING_IMG].img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image[CEILING_IMG].img); */
}