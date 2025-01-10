/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_empty_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:59:20 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/10 11:59:49 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Ensures that there are no empty lines in the middle of the map

void	check_map_empty_lines(t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (tmp && tmp->type != MAP_LINE)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->type == EMPTY_LINE)
			clean_list_with_syntax_error(list, i, tmp->line, "Map has a space line\n");
		i++;
		tmp = tmp->next;
	}
}