/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:42:20 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/24 14:25:12 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// check player's starting position and direction within the map
// y = row index
// x = column index

void	get_player_position(t_data **data)
{
	int	x;
	int	y;
	
	y = 0;
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			if (direction_char((*data)->map[y][x]))
			{
				(*data)->player_x = x;
				(*data)->player_y = y;
				(*data)->player_direction = (*data)->map[y][x];
				convert_dir_to_radian(data, (*data)->map[y][x]);
			}
			x++;
		}
		y++;
	}
}

int	direction_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

// Converts the player’s direction to a radian value for easier trigonometric functions

void	convert_dir_to_radian(t_data **data, char player_pos)
{
	if (player_pos == 'N')
		(*data)->player_direction_radian = M_PI / 2;  // = 90 degree
	else if (player_pos == 'S')
		(*data)->player_direction_radian = 3 * (M_PI / 2); // = 270 degree
	else if (player_pos == 'W')
		(*data)->player_direction_radian = M_PI; // = 180 degree
	else if (player_pos == 'E')
		(*data)->player_direction_radian = 0.0; // = 0 degree
}
