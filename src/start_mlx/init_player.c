/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:54:00 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/31 12:03:41 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Iterate through the map (row by row)
// Locates the player's starting position in the parsed map,
// initializes its state, and updates the map.

void	find_player(char **parsed_map, t_mlx *mlx)
{
	int		position[2]; // [0] = column, [1] = row
	char	*row;
	char	**map_backup;

	map_backup = parsed_map;
	position[1] = 0;
	while (parsed_map)
	{
		position[0] = 0;
		row = *parsed_map;
		while (*row)
		{
			if (is_player(*row, &mlx->player[ANGLE]))
			{
				*row = '0';
				init_player(mlx, position);
				return ;
			}
			position[0]++;
			row++;
		}
		position[1]++;
		parsed_map++;
	}
	parsed_map = map_backup;
}


//  initializes the player's position and movement attributes int_mlx struct

void	init_player(t_mlx *mlx, int *position)
{
	mlx->player[X] = position[0] + 0.5f; // Adds 0.5 to the grid position so the player starts at the center of the cell rather than at its edge
	mlx->player[Y] = position[1] + 0.5f;
	mlx->player[X_PIXEL] = mlx->player[X] * CELL_SIZE; // Converts the X-coordinate to pixel units (assuming each grid cell is 64x64 pixels
	mlx->player[Y_PIXEL] = mlx->player[Y] * CELL_SIZE;
	mlx->movement_vector[0] = cos(mlx->player[ANGLE]) * MOV_SPEED; //  horizontal (5 = movement speed)
	mlx->movement_vector[1] = sin(mlx->player[ANGLE]) * MOV_SPEED; //  vertical
	mlx->player[SIGHT] = PLAYER_SIGHT * (M_PI / 180);
}


// Check if the current character (*s) is a valid player start position.

bool	is_player(char c, double *angle)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (c == 'N')
			*angle = 3 * M_PI_2; // = 270 degree
		else if (c == 'S')
			*angle = M_PI_2; // = 90 degree
		else if (c == 'W')
			*angle = M_PI; // = 180 degree
		else if (c == 'E')
			*angle = 0; // = 0 degree
		return (true);
	}
	return (false);
}