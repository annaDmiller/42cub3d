/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:02:42 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/21 16:20:48 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Check that map is enclosed by walls (1) and contains no invalid openings (0) near the edges
// 1. Checks the top and bottom rows of the map
// 2. Validate the first and last characters of every row (ensures vertical walls).
// 3. Inspect the internal structure of the map

void	check_map_is_closed(t_data **data)
{
	if (check_close_chars((*data)->map[0]))
		clean_data_map_exit(data, 0, "check_close_chars_Map should be closed by char 1\n");
	if (check_close_chars((*data)->map[(*data)->map_height - 1]))
		clean_data_map_exit(data, ((*data)->map_height - 1), "check_close_chars_2_Map should be closed by char 1\n");
	check_first_last_char(data);
	check_inside_map(data);
}

// Verifies that a string (map row) contains only 1 or spaces
// If char is not 1 or a space, it returns (EXIT_FAILURE)
// Return (EXIT_SUCCESS) if the string is valid

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


// Check the first and last characters of each row are enclosed properly

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
		if ((map[y][0] == '0' || map[y][width - 1] == '0') || \
			(map[y][0] == 'N' || map[y][width - 1] == 'N') || \
			(map[y][0] == 'S' || map[y][width - 1] == 'S') || \
			(map[y][0] == 'E' || map[y][width - 1] == 'E') || \
			(map[y][0] == 'W' || map[y][width - 1] == 'W'))
			clean_data_map_exit(data, y, "check_first_last_char_Map should be closed by char 1\n");
		y++;
	}
}

//Check the inner map structure, ensuring no 0 (open space) is adjacent to an invalid character (or out-of-bounds)

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

// Check if the adjacent cell in chosen direction is a space ( )
// If yes, clean and exit

void	check_direction_side(t_data **data, int x, int y, int direction)
{
	if (direction == NORTH && (*data)->map[y - 1][x] == ' ')
		clean_data_map_exit(data, y, "check_direction_side0_Map should be closed by char 1\n");
	if (direction == SOUTH && (*data)->map[y + 1][x] == ' ')
		clean_data_map_exit(data, y, "check_direction_side1_Map should be closed by char 1\n");
	if (direction == WEST && (*data)->map[y][x - 1] == ' ')
		clean_data_map_exit(data, y, "check_direction_side2_Map should be closed by char 1\n");
	if (direction == EAST && (*data)->map[y][x + 1] == ' ' )
		clean_data_map_exit(data, y, "check_direction_side3_Map should be closed by char 1\n");
}