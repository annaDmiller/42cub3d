/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:43:14 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/07 15:48:50 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/cub3d.h"

t_list	*ft_lstnew(char *line)
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
