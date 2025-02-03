/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:02:42 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/03 16:01:35 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_map_is_closed(t_data **data)
{
	if (check_close_chars((*data)->map[0]))
		clean_data_map_exit(data, 0, "Map should be closed by char 1\n");
	if (check_close_chars((*data)->map[(*data)->map_height - 1]))
		clean_data_map_exit(data, ((*data)->map_height - 1),
			"Map should be closed by char 1\n");
	check_first_last_char(data);
	check_inside_map(data);
}

int	check_close_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	check_first_last_char(t_data **data)
{
	int		y;
	char	**map;
	int		width;

	y = 1;
	map = (*data)->map;
	width = (*data)->map_width;
	while (y < (*data)->map_height - 1)
	{
		if ((map[y][0] == '0' || map[y][width - 1] == '0') || (map[y][0] == 'N'
				|| map[y][width - 1] == 'N') || (map[y][0] == 'S'
				|| map[y][width - 1] == 'S') || (map[y][0] == 'E'
				|| map[y][width - 1] == 'E') || (map[y][0] == 'W'
				|| map[y][width - 1] == 'W'))
			clean_data_map_exit(data, y, "Map should be closed by char 1\n");
		y++;
	}
}

void	check_inside_map(t_data **data)
{
	int	x;
	int	y;

	y = 1;
	while (y < (*data)->map_height)
	{
		x = 1;
		while (x < (*data)->map_width)
		{
			if ((*data)->map[y][x] == '0')
			{
				check_direction_side(data, x, y, NORTH);
				check_direction_side(data, x, y, SOUTH);
				check_direction_side(data, x, y, WEST);
				check_direction_side(data, x, y, EAST);
			}
			x++;
		}
		y++;
	}
}

void	check_direction_side(t_data **data, int x, int y, int direction)
{
	if (direction == NORTH && (*data)->map[y - 1][x] == ' ')
		clean_data_map_exit(data, y, "Map should be closed by char 1\n");
	if (direction == SOUTH && (*data)->map[y + 1][x] == ' ')
		clean_data_map_exit(data, y, "Map should be closed by char 1\n");
	if (direction == WEST && (*data)->map[y][x - 1] == ' ')
		clean_data_map_exit(data, y, "Map should be closed by char 1\n");
	if (direction == EAST && (*data)->map[y][x + 1] == ' ')
		clean_data_map_exit(data, y, "Map should be closed by char 1\n");
}
