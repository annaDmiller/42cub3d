/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:36:57 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:10 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_casting(t_mlx *mlx)
{
	float	inter_hor;
	float	inter_vert;
	int	screen_line;

	mlx->ray->angle = mlx->player[ANGLE] - (mlx->player[SIGHT] / 2);
	screen_line = 0;
	render_floor_ceiling(mlx);
	while (screen_line < SCREEN_WIDTH)
	{
		inter_hor = find_horiz_intersection(mlx,
				norming_angle(mlx->ray->angle));
		inter_vert = find_vert_intersection(mlx,
				norming_angle(mlx->ray->angle));
		if (inter_vert <= inter_hor)
		{
			mlx->ray->dist = inter_vert;
			mlx->ray->hit_vert_wall = 1;
		}
		else
		{
			mlx->ray->dist = inter_hor;
			mlx->ray->hit_vert_wall = 0;
		}
		find_wall_hit_point(mlx);
		draw_line(mlx, screen_line);
		screen_line++;
		mlx->ray->angle += (mlx->player[SIGHT] / SCREEN_WIDTH);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->image[PLACEHOLDER].img, 0, 0);
	return ;
}
