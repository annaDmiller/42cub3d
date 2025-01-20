/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_empty_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:31:04 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/20 12:56:03 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// The map is init with placeholdes (empty spaces) for later fill with actual map data
// "     "
// "     "
// "     "
// NULL

void	init_empty_map(t_data **data, t_list **list)
{
	int     i;

	i = 0;
	(*data)->map = (char **)malloc(sizeof(char *) * ((*data)->map_height + 1)); // malloc for all rows
	if (!(*data)->map)
		clean_all_exit(data, list, "Map malloc error\n");
	while (i < (*data)->map_height)
	{
		(*data)->map[i] = (char *)malloc(sizeof(char) * ((*data)->map_width + 1)); // malloc for each row
		if (!(*data)->map[i])
		{
			free_array((*data)->map);
			clean_all_exit(data, list, "Map malloc error\n");
		}
		(*data)->map[i] = ft_memset((*data)->map[i], ' ', (*data)->map_width);
		(*data)->map[i][(*data)->map_width] = '\0';
		i++;
	}
	(*data)->map[i] = NULL;
}