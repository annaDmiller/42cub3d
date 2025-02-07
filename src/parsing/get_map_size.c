/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:54:28 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:12:47 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_map_size(t_data **data, t_list **list)
{
	int		height;
	int		width;
	t_list	*tmp;

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
