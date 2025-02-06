/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:37:11 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/06 17:27:06 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_img	*check_side(t_mlx *mlx, int hit_vert_wall);
static float	find_x_offset(t_mlx *mlx, int hit_vert_wall, t_img *texture);

void	paint_wall(t_mlx *mlx, int x_img, float bot_pxl, float top_pxl)
{
	t_img	*texture;
	float	x_text;
	float	y_step;
	float	y_text;
	int		color;

	texture = check_side(mlx, mlx->ray->hit_vert_wall);
	x_text = find_x_offset(mlx, mlx->ray->hit_vert_wall, texture);
	y_step = texture->height / (mlx->ray->wall_height);
	y_text = ((top_pxl - (SCREEN_HEIGHT / 2) + (mlx->ray->wall_height
					/ 2)) * y_step);
	if (y_text < 0)
		y_text = 0;
	while (top_pxl < bot_pxl)
	{
		color = get_color((int)x_text, (int)y_text, texture);
		put_pix_to_img(mlx, x_img, (int)top_pxl, color);
		y_text += y_step;
		top_pxl++;
	}
	return ;
}

static t_img	*check_side(t_mlx *mlx, int hit_vert_wall)
{
	mlx->ray->angle = norming_angle(mlx->ray->angle);
	if (hit_vert_wall == 1)
	{
		if (mlx->ray->angle > M_PI_2 && mlx->ray->angle < 3 * M_PI_2)
			return (&(mlx->image[WALL_WEST]));
		else
			return (&(mlx->image[WALL_EAST]));
	}
	else
	{
		if (mlx->ray->angle > 0 && mlx->ray->angle < M_PI)
			return (&(mlx->image[WALL_SOUTH]));
		else
			return (&(mlx->image[WALL_NORTH]));
	}
}

static float	find_x_offset(t_mlx *mlx, int hit_vert_wall, t_img *texture)
{
	if (hit_vert_wall == 1)
		return (fmodf(mlx->ray->wall_hit_y * (texture->width / CELL_SIZE),
				texture->width));
	return (fmodf(mlx->ray->wall_hit_x * (texture->width / CELL_SIZE),
			texture->width));
}
