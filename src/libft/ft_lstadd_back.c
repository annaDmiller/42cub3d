/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:48:36 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/10 16:00:39 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*ft_lstadd_back(t_list **list, t_list *elem)
{
	if (*list)
		ft_lstlast(*list)->next = elem;
	else
		*list = elem;
	return (*list);
}
