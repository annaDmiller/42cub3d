/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:45:29 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/14 17:45:31 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*heap_s;

	i = 0;
	while (s[i] != '\0')
		i++;
	heap_s = (char *)malloc((i + 1) * sizeof(char));
	if (!heap_s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		heap_s[i] = s[i];
		i++;
	}
	heap_s[i] = '\0';
	return (heap_s);
}
