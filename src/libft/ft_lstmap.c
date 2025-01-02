/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:43:03 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/14 17:43:07 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*save;

	if (!lst || !f || !del)
		return (NULL);
	n_list = ft_lstnew((*f)(lst->content));
	if (!n_list)
		return (NULL);
	save = n_list;
	lst = lst->next;
	while (lst)
	{
		n_list->next = ft_lstnew(f(lst->content));
		if (!n_list->content)
		{
			ft_lstclear(&save, del);
			return (NULL);
		}
		n_list = n_list->next;
		lst = lst->next;
	}
	n_list->next = NULL;
	return (save);
}
