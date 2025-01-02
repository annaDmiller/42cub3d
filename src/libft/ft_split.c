/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:44:38 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/16 14:08:37 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_string_copy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	if (size < 1)
		return (count);
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

static int	ft_count_substrings(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
	str++;
	}
	return (count);
}

static char	*ft_copy_substring(const char *start, int length)
{
	char	*substr;

	substr = (char *)malloc((length + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_string_copy(substr, (char *)start, length);
	return (substr);
}

static int	ft_free_result(char **result, int count)
{
	if (result[count] == NULL)
	{
		count--;
		while (count > 0)
		{
			free(result[count]);
			count--;
		}
		free(result[0]);
		free(result);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char const		*start;
	char			**result;
	int				index;

	index = 0;
	result = (char **)malloc((ft_count_substrings(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[index] = ft_copy_substring(start, s - start);
			if (ft_free_result(result, index))
				return (NULL);
			index++;
		}
		else
			s++;
	}
	result[index] = NULL;
	return (result);
}
