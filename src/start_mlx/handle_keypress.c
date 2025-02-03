/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:18:29 by olly              #+#    #+#             */
/*   Updated: 2025/02/03 16:46:17 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_wall(t_mlx *mlx, double new_pos[2]);

static void	update_angle_and_movement_vector(t_mlx *mlx, char move,
		double new_pos[2])
{
	double	dist[2];

	dist[X] = cos(mlx->player[ANGLE]) * MOV_SPEED;
	dist[Y] = sin(mlx->player[ANGLE]) * MOV_SPEED;
	if (move == 'W')
	{
		new_pos[X] = mlx->player[X_PIXEL] + dist[X];
		new_pos[Y] = mlx->player[Y_PIXEL] + dist[Y];
	}
	else if (move == 'S')
	{
		new_pos[X] = mlx->player[X_PIXEL] - dist[X];
		new_pos[Y] = mlx->player[Y_PIXEL] - dist[Y];
	}
	else if (move == 'A')
	{
		new_pos[X] = mlx->player[X_PIXEL] + dist[Y];
		new_pos[Y] = mlx->player[Y_PIXEL] - dist[X];
	}
	else if (move == 'D')
	{
		new_pos[X] = mlx->player[X_PIXEL] - dist[Y];
		new_pos[Y] = mlx->player[Y_PIXEL] + dist[X];
	}
	if (new_pos[Y] < 0 || new_pos[X] < 0 || new_pos[Y]
		/ CELL_SIZE > mlx->map->map_height || new_pos[X]
		/ CELL_SIZE > mlx->map->map_width)
		return ;
	if (check_wall(mlx, new_pos))
	{
		mlx->player[X_PIXEL] = new_pos[X];
		mlx->player[Y_PIXEL] = new_pos[Y];
	}
	return ;
}

static int	check_wall(t_mlx *mlx, double new_pos[2])
{
	if (mlx->map->map[(int)new_pos[Y] / CELL_SIZE][(int)new_pos[X]
		/ CELL_SIZE] == '1')
		return (0);
	if (mlx->map->map[(int)mlx->player[Y_PIXEL] / CELL_SIZE][(int)new_pos[X]
		/ CELL_SIZE] == '1')
		return (0);
	if (mlx->map->map[(int)new_pos[Y] / CELL_SIZE][(int)mlx->player[X_PIXEL]
		/ CELL_SIZE] == '1')
		return (0);
	if (mlx->player[Y_PIXEL] - new_pos[Y] > 0 && mlx->map->map[((int)new_pos[Y]
				- 1) / CELL_SIZE][(int)new_pos[X] / CELL_SIZE] == '1')
		return (0);
	if (mlx->player[X_PIXEL] - new_pos[X] > 0 && mlx->map->map[(int)new_pos[Y]
			/ CELL_SIZE][((int)new_pos[X] - 1) / CELL_SIZE] == '1')
		return (0);
	return (1);
}

static void	players_movement(t_mlx *mlx, char move)
{
	double	negative_one_offsets[2] = {-1, -1};

	if (move == 'R' || move == 'L')
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

int	handle_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		clean_mlx(mlx);
		exit(0);
	}
	else if (keycode == D_KEY)
		players_movement(mlx, 'D');
	else if (keycode == A_KEY)
		players_movement(mlx, 'A');
	else if (keycode == S_KEY)
		players_movement(mlx, 'S');
	else if (keycode == W_KEY)
		players_movement(mlx, 'W');
	else if (keycode == LEFT)
		players_movement(mlx, 'L');
	else if (keycode == RIGHT)
		players_movement(mlx, 'R');
	return (0);
}

int	handle_close(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	clean_mlx(mlx);
	exit(0);
	return (0);
}
