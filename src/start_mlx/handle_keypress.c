/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olly <olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:18:29 by olly              #+#    #+#             */
/*   Updated: 2025/01/28 17:34:20 by olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Updates the player's angle and movement vector based on the key pressed

static void	update_angle_and_movement_vector(t_mlx *mlx, char move, double new_pos[2])
{
	double	dist[2];

	dist[X] = cos(mlx->player[ANGLE]) * MOV_SPEED;
	dist[Y] = sin(mlx->player[ANGLE]) * MOV_SPEED;
	if (move == 'W')
	{
		new_pos[X] = mlx->player[X] + dist[X];
		new_pos[Y] = mlx->player[Y] + dist[Y];
	}
	else if (move == 'S')
	{
		new_pos[X] = mlx->player[X] - dist[X];
		new_pos[Y] = mlx->player[Y] - dist[Y];
	}
	else if (move == 'A')
	{
		new_pos[X] = mlx->player[X] - dist[Y];
		new_pos[Y] = mlx->player[Y] + dist[X];
	}
	else if (move == 'D') 
	{
		new_pos[X] = mlx->player[X] + dist[Y];
		new_pos[Y] = mlx->player[Y] - dist[X];
	}
	if (new_pos[Y] >= 0 && new_pos[X] >= 0
		&& mlx->map->map[(int)new_pos[Y]][(int)new_pos[X]] != '1') 	// Collision detection
	{
		mlx->player[X] = new_pos[X];
		mlx->player[Y] = new_pos[Y];
	}
}
// Handles the player's movement based on the key pressed
// rotation_steps[0] is for turning right, 
// rotation_steps[1]) is for turning left

static void players_movement(t_mlx *mlx, char move, double rotation_steps[2])
{
    double negative_one_offsets[2] = {-1, -1};

    if (move == 'R' || move == 'L') {
        update_angle_and_movement_vector(mlx, move, rotation_steps);
        return;
    }
    else if (move == 'W')
        update_angle_and_movement_vector(mlx, 'W', negative_one_offsets);
    else if (move == 'S') 
        update_angle_and_movement_vector(mlx, 'S', negative_one_offsets);
    else if (move == 'A')
        update_angle_and_movement_vector(mlx, 'A', negative_one_offsets);
    else if (move == 'D') 
        update_angle_and_movement_vector(mlx, 'D', negative_one_offsets);
    mlx->player[X_PIXEL] = (mlx->player[X] * 64);
    mlx->player[Y_PIXEL] = (mlx->player[Y] * 64);
}

// Handles the keypress event

int	handle_keypress(int keycode, t_mlx *mlx)
{
	double rotation_offsets[2] = {ROT_SPEED, -ROT_SPEED};
	
	if (keycode == ESCAPE)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		clean_mlx(mlx);
		exit(0);
	}
	else if (keycode == D_KEY)
		players_movement(mlx, 'D', rotation_offsets);
	else if (keycode == A_KEY)
		players_movement(mlx, 'A', rotation_offsets);
	else if (keycode == S_KEY)
		players_movement(mlx, 'S', rotation_offsets);
	else if (keycode == W_KEY)
		players_movement(mlx, 'W', rotation_offsets);
	else if (keycode == LEFT)
		players_movement(mlx, 'L', rotation_offsets);
	else if (keycode == RIGHT)
		players_movement(mlx, 'R', rotation_offsets);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	return (0);
}

int	handle_close(t_mlx *mlx)
{
	clean_mlx(mlx);
	exit(0);
	return (0);
} 