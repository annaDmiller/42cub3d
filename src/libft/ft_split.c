/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:49:23 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/04 13:39:17 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_count_words(char *str, char c)
{
	int	wcount;

	wcount = 0;
	while (*str)
	{
		if (*str != c && (*(str + 1) == '\0' || *(str + 1) == c))
			wcount++;
		str++;
	}
	return (wcount);
}

static int	ft_wordlen(char *str, char c)
{
	int	wlen;

	wlen = 0;
	while (str[wlen] && str[wlen] != c)
		wlen++;
	return (wlen);
}

static void	*ft_free(char **words, int wcount)
{
	while (wcount--)
		free(words[wcount]);
	free(words);
	return (NULL);
}

static char	**fill(char *str, int wcount, char c, char **words)
{
	int	i;
	int	j;
	int	wlen;

	i = 0;
	while (i < wcount)
	{
		while (*str == c)
			str++;
		wlen = ft_wordlen(str, c);
		words[i] = (char *)malloc(sizeof(char) * (wlen + 1));
		if (!words[i])
			return (ft_free(words, i));
		j = 0;
		while (j < wlen)
			words[i][j++] = *str++;
		words[i][j] = '\0';
		i++;
	}
	words[i] = NULL;
	return (words);
}

char	**ft_split(t_data **data, t_list **list, char *str, char c)
{
	char	**words;
	int		wcount;

	if (!str)
		return (NULL);
	wcount = ft_count_words(str, c);
	if (wcount != 3)
	{
		if (wcount < 3)
		{
			free(str);
			clean_all_exit(data, list,
				"Missing RGB value: need 3 parameters\n");
		}
		if (wcount > 3)
		{
			free(str);
			clean_all_exit(data, list, "Need only 3 parameters\n");
		}
	}
	words = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!words)
		return (NULL);
	words = fill(str, wcount, c, words);
	return (words);
}
