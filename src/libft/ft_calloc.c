/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:41:10 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/14 17:41:14 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c_alloc;

	if (size && SIZE_MAX / size < count)
		return (NULL);
	c_alloc = (void *)(malloc(count * size));
	if (!c_alloc)
		return (NULL);
	ft_bzero(c_alloc, count * size);
	return (c_alloc);
}
