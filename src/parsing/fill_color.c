/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:54:17 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/04 13:38:27 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_colors(t_data **data, t_list **list, int *dst_rgb, char *src)
{
	t_list	*tmp;
	char	*to_split;
	char	*cleaned_line;

	tmp = *list;
	while (tmp)
	{
		cleaned_line = ft_strtrim(tmp->line, " \t");
		if (!cleaned_line)
			clean_all_exit(data, list, "Memory allocation failed\n");
		if (ft_strncmp(cleaned_line, src, 2) == 0)
		{
			to_split = trimmed_string(cleaned_line, src);
			free(cleaned_line);
			if (!to_split)
				clean_all_exit(data, list, "RGB data init failed\n");
			to_split = remove_spaces_and_tabs(to_split);
			get_rgb_value(data, list, &to_split, dst_rgb);
			free(to_split);
			return ;
		}
		free(cleaned_line);
		tmp = tmp->next;
	}
}

int	get_rgb_value(t_data **data, t_list **list, char **str, int *dst_rgb)
{
	char	**array;
	int		rgb[3];

	set_tab_with_zero(rgb, 3, 0);
	array = ft_split(data, list, *str, ',');
	if (!array)
		clean_all_exit(data, list, "Split RGB on commas Malloc fail\n");
	check_value_limits(data, list, array, str);
	if (!array[RED_RGB] || !array[GREEN_RGB] || !array[BLUE_RGB])
		clean_all_exit(data, list, "Invalid RGB format\n");
	rgb[RED_RGB] = ft_atoi(array[RED_RGB]);
	rgb[GREEN_RGB] = ft_atoi(array[GREEN_RGB]);
	rgb[BLUE_RGB] = ft_atoi(array[BLUE_RGB]);
	dst_rgb[RED_RGB] = rgb[RED_RGB];
	dst_rgb[GREEN_RGB] = rgb[GREEN_RGB];
	dst_rgb[BLUE_RGB] = rgb[BLUE_RGB];
	free_array(array);
	return (0);
}

void	check_value_limits(t_data **data, t_list **list, char **array,
		char **str)
{
	int	i;
	int	len;
	int	nbr;

	i = 0;
	while (array && array[i])
	{
		if (!array[i])
			clean_all_exit(data, list, "RGB value missing\n");
		len = count_digits(array[i]);
		nbr = ft_atoi(array[i]);
		if (len == -1 || len > 3 || nbr > 255)
		{
			free(*str);
			free_array(array);
			if (len == -1)
				clean_all_exit(data, list, "RGB value syntax error\n");
			if (len > 3)
				clean_all_exit(data, list, "RGB value is too long\n");
			if (nbr > 255)
				clean_all_exit(data, list, "RGB value is too big\n");
		}
		i++;
	}
}

int	count_digits(char *str)
{
	int	i;

	i = 0;
	while (*str == ' ')
		str++;
	while (ft_isdigit(*str))
	{
		i++;
		str++;
	}
	while (*str == ' ')
		str++;
	if (ft_isdigit(*str))
		return (-1);
	return (i);
}

char	*remove_spaces_and_tabs(char *str)
{
	char	*result;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	result = (char *)malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			result[j] = str[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	free(str);
	return (result);
}
