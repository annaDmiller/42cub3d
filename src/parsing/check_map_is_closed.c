/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:00:57 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:12:47 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_map_is_closed(t_data **data)
{
	char	**temp_map;
	int		start_x;
	int		start_y;

	temp_map = copy_map(*data);
	if (!temp_map)
		clean_data_map_exit(data, 0, "Memory allocation failed\n");
	find_start_point(temp_map, *data, &start_x, &start_y);
	flood_fill(temp_map, start_x, start_y, *data);
	free_map_copy(temp_map, (*data)->map_height);
}

void	flood_fill(char **map, int x, int y, t_data *data)
{
	if (is_out_of_bounds(x, y, data))
	{
		free_map_copy(map, data->map_height);
		clean_data_map_exit(&data, y, "Map should be closed by char 1\n");
	}
	if (map[y][x] == ' ')
	{
		free_map_copy(map, data->map_height);
		clean_data_map_exit(&data, y, "Map should be closed by char 1\n");
	}
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}

char	**copy_map(t_data *data)
{
	char	**temp_map;
	int		i;

	temp_map = malloc((data->map_height + 1) * sizeof(char *));
	if (!temp_map)
		return (NULL);
	i = 0;
	while (i < data->map_height)
	{
		temp_map[i] = ft_strdup(data->map[i]);
		if (!temp_map[i])
		{
			free_map_copy(temp_map, i);
			return (NULL);
		}
		i++;
	}
	temp_map[i] = NULL;
	return (temp_map);
}

void	find_start_point(char **map, t_data *data, int *start_x, int *start_y)
{
	int	x;
	int	y;
	int	found;

	y = 0;
	found = 0;
	while (y < data->map_height && !found)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				*start_x = x;
				*start_y = y;
				found = 1;
				break ;
			}
			x++;
		}
		y++;
	}
}

int	is_out_of_bounds(int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x >= data->map_width || y >= data->map_height)
		return (1);
	return (0);
}
