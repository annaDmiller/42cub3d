/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:13:18 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/06 17:32:13 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(char *src)
{
	char	*str;
	char	*p;

	str = malloc((ft_strlen(src) + 1) * sizeof(char));
	p = str;
	if (str == NULL)
	{
		return (0);
	}
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (str);
}
