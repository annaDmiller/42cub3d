/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:59:15 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:12:47 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_set(s1[start], set))
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end > start && is_set(s1[end - 1], set))
		end--;
	trimmed = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start < end)
		trimmed[i++] = s1[start++];
	trimmed[i] = '\0';
	return (trimmed);
}
