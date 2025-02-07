/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:52:51 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:14:16 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_texture(t_data **data, t_list **list, char **dest, char *src)
{
	t_list	*tmp;
	char	*trimmed;

	tmp = *list;
	while (tmp)
	{
		trimmed = ft_strtrim(tmp->line, " \t");
		if (!trimmed)
			clean_all_exit(data, list, "Memory allocation failed\n");
		if (ft_strncmp(trimmed, src, 3) == 0)
		{
			*dest = trimmed_string(trimmed, src);
			free(trimmed);
			if (!*dest)
				clean_all_exit(data, list, "Texture data init failed\n");
			return ;
		}
		free(trimmed);
		tmp = tmp->next;
	}
	clean_all_exit(data, list, "Error: One or more textures missing\n");
}

char	*trimmed_string(char *str, char *prefix)
{
	int		len;
	char	*substr;

	if (!str || !prefix)
		return (NULL);
	str += ft_strlen(prefix);
	while (*str == ' ' || *str == '\t')
		str++;
	len = ft_strlen(str);
	while (len > 0 && str[len - 1] == ' ')
		len--;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	substr[len] = '\0';
	while (len--)
		substr[len] = str[len];
	return (substr);
}
