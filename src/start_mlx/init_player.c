/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:54:00 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/03 16:35:42 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	find_player(char **parsed_map, t_mlx *mlx)
{
	int		position[2];
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

void	init_player(t_mlx *mlx, int *position)
{
	mlx->player[X] = position[0] + 0.5f;
	mlx->player[Y] = position[1] + 0.5f;
	mlx->player[X_PIXEL] = mlx->player[X] * CELL_SIZE;
	mlx->player[Y_PIXEL] = mlx->player[Y] * CELL_SIZE;
	mlx->movement_vector[0] = cos(mlx->player[ANGLE]) * MOV_SPEED;
	mlx->movement_vector[1] = sin(mlx->player[ANGLE]) * MOV_SPEED;
	mlx->player[SIGHT] = PLAYER_SIGHT * (M_PI / 180);
}

bool	is_player(char c, double *angle)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (c == 'N')
			*angle = 3 * M_PI_2;
		else if (c == 'S')
			*angle = M_PI_2;
		else if (c == 'W')
			*angle = M_PI;
		else if (c == 'E')
			*angle = 0;
		return (true);
	}
	return (false);
}
