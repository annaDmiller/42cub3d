/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:30:27 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/03 16:39:16 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	count_players(t_data **data)
{
	int	x;
	int	y;
	int	player;

	y = 0;
	player = 0;
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			if (direction_char((*data)->map[y][x]))
				player++;
			x++;
		}
		y++;
	}
	if (player == 0)
		clean_data_map_exit(data, 0, "No player position found in the map\n");
	if (player > 1)
		clean_data_map_exit(data, 0,
			"Multiple player positions found in the map\n");
}
