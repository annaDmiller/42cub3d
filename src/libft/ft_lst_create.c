/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:47:41 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:12:47 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_list	*ft_lst_create(char *line)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->line = line;
	elem->line_size = ft_strlen(elem->line);
	elem->type = set_line_type(elem->line);
	elem->next = NULL;
	return (elem);
}
