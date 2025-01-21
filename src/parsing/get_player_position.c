/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:42:20 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/21 12:21:02 by okapshai         ###   ########.fr       */
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
	int	player_count;

	y = 0;
	player_count = 0;
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			if (direction_char((*data)->map[y][x]))
			{
				player_count++;
				(*data)->player_x = x;
				(*data)->player_y = y;
				(*data)->player_direction = (*data)->map[y][x];
			}
			x++;
		}
		y++;
	}
	if (player_count == 0)
        clean_data_map_exit(data, 0, "No player position found in the map.\n");
	if (player_count > 1)
        clean_data_map_exit(data, 0, "Multiple player positions found in the map.\n");
    }


int	direction_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}
