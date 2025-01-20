/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:54:28 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/20 11:57:02 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Get the size of the map : height (number of lines) and width (maximum line length)

void	get_map_size(t_data **data, t_list **list)
{
	t_list	*tmp;
	int		height;
	int		width;

	tmp = *list;
	height = 0;
	width = 0;
	while (tmp && tmp->type != MAP_LINE)
		tmp = tmp->next;
	while (tmp)
	{
		height++;
		if (width < ft_strlen(tmp->line))
			width = ft_strlen(tmp->line);
		tmp = tmp->next;
	}
	(*data)->map_height = height;
	(*data)->map_width = width;
}