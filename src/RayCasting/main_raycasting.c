/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:36:57 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:12:47 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_least_dist(t_mlx *mlx, float hor, float vert);

void	ray_casting(t_mlx *mlx)
{
	float	inter_hor;
	float	inter_vert;
	int		screen_line;

	mlx->ray->angle = mlx->player[ANGLE] - (mlx->player[SIGHT] / 2);
	screen_line = 0;
	render_floor_ceiling(mlx);
	while (screen_line < SCREEN_WIDTH)
	{
		inter_hor = find_horiz_intersection(mlx,
				norming_angle(mlx->ray->angle));
		inter_vert = find_vert_intersection(mlx,
				norming_angle(mlx->ray->angle));
		check_least_dist(mlx, inter_hor, inter_vert);
		draw_line(mlx, screen_line);
		screen_line++;
		mlx->ray->angle += (mlx->player[SIGHT] / SCREEN_WIDTH);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->image[PLACEHOLDER].img, 0, 0);
	return ;
}

static void	check_least_dist(t_mlx *mlx, float hor, float vert)
{
	if (vert <= hor)
	{
		mlx->ray->dist = vert;
		mlx->ray->hit_vert_wall = 1;
	}
	else
	{
		mlx->ray->dist = hor;
		mlx->ray->hit_vert_wall = 0;
	}
	find_wall_hit_point(mlx);
	return ;
}
