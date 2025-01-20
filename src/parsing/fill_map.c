/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:01:12 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/20 13:13:54 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Reads the map data from the linked list and places it into the 2D array (*data)->map)

void	fill_map(t_data **data, t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (tmp && tmp->type != MAP_LINE)
		tmp = tmp->next;
	while (i < (*data)->map_height && tmp)
	{
		(*data)->map[i] = copy_content((*data)->map[i], tmp->line);
		tmp = tmp->next;
		i++;
	}
}

// copy the content of the current node's line into the corresponding row of the map

char	*copy_content(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}