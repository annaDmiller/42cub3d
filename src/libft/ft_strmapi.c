/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:46:26 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/14 17:46:28 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map_s;
	unsigned int	i;

	map_s = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!map_s || !s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		map_s[i] = (*f)(i, s[i]);
		i++;
	}
	map_s[i] = '\0';
	return (map_s);
}
