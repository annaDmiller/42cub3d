/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:47:28 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/10 16:07:58 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lst_clear(t_list **lst)
{
	t_list	*ptr;
	t_list	*next;

	ptr = *lst;
	while (ptr)
	{
		next = ptr->next;
		free(ptr->line);
		free(ptr);
		ptr = next;
	}
}
