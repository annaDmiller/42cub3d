/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_empty_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:59:20 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:00:15 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
			clean_list_with_syntax_error(list, i, tmp->line,
				"Map has an empty line\n");
		i++;
		tmp = tmp->next;
	}
}
