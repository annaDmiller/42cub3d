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

/* void	print_map(t_data *data)
{
    int i;

    i = 0;
    while (i < data->map_height)
    {
        printf("%s\n", data->map[i]);
        i++;
    }
} */

// Reads the map data from the linked list and places it into the 2D array (*data)->map)

void	fill_map(t_data **data, t_list **list)
{
	t_list	*tmp;
	int		i;
	int 	j;

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
	// Replace all spaces with '1' (sort of flood fill)
    i = 0;
    while (i < (*data)->map_height)
    {
        j = 0;
        while (j < (*data)->map_width)
        {
            if ((*data)->map[i][j] == ' ')
                (*data)->map[i][j] = '1';
            j++;
        }
        i++;
    }
	//print_map(*data);
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