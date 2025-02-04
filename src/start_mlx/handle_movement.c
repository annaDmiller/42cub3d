/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:35:15 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/04 13:46:06 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_valid_position(t_mlx *mlx, double new_pos[2])
{
	if (new_pos[Y] < 0 || new_pos[X] < 0 || new_pos[Y]
		/ CELL_SIZE > mlx->map->map_height || new_pos[X]
		/ CELL_SIZE > mlx->map->map_width)
		return (0);
	return (1);
}

static void	update_player_position(t_mlx *mlx, double new_pos[2])
{
	if (check_wall(mlx, new_pos))
	{
		mlx->player[X_PIXEL] = new_pos[X];
		mlx->player[Y_PIXEL] = new_pos[Y];
	}
}

static void	update_angle_and_movement_vector(t_mlx *mlx, char move,
		double new_pos[2])
{
	double	dist[2];

	calculate_movement_vector(mlx, dist);
	set_new_position(mlx, move, new_pos, dist);
	if (!is_valid_position(mlx, new_pos))
		return ;
	update_player_position(mlx, new_pos);
}

static void	handle_rotation(t_mlx *mlx, char move)
{
	if (move == 'R')
		mlx->player[ANGLE] += ROT_SPEED;
	else
		mlx->player[ANGLE] -= ROT_SPEED;
	if (mlx->player[ANGLE] < 0)
		mlx->player[ANGLE] += 2 * M_PI;
	else if (mlx->player[ANGLE] > 2 * M_PI)
		mlx->player[ANGLE] -= 2 * M_PI;
	ray_casting(mlx);
}

void	players_movement(t_mlx *mlx, char move)
{
	double	negative_one_offsets[2];

	negative_one_offsets[0] = -1;
	negative_one_offsets[1] = -1;
	if (move == 'R' || move == 'L')
	{
		handle_rotation(mlx, move);
		return ;
	}
	if (move == 'W')
		update_angle_and_movement_vector(mlx, 'W', negative_one_offsets);
	else if (move == 'S')
		update_angle_and_movement_vector(mlx, 'S', negative_one_offsets);
	else if (move == 'A')
		update_angle_and_movement_vector(mlx, 'A', negative_one_offsets);
	else if (move == 'D')
		update_angle_and_movement_vector(mlx, 'D', negative_one_offsets);
	ray_casting(mlx);
}
