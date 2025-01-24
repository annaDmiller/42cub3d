/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:23:35 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/24 16:08:47 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Validates the syntax of each line in the list based on its type (ex: map,
//	texture, color).

void	check_map_syntax(t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	if (!tmp)
		clean_list(list, "Map is empty\n");
	while (tmp)
	{
		if (tmp->type == ERROR_LINE)
			clean_list_with_syntax_error(list, i, tmp->line,
				"Syntax error in map file\n");
		else if (tmp->type == TEXTURE_LINE
			&& check_directions_syntax(tmp->line))
			clean_list_with_syntax_error(list, i, tmp->line,
				"Syntax error in texture line\n");
		else if (tmp->type == COLOR_LINE && check_color_syntax(tmp->line))
			clean_list_with_syntax_error(list, i, tmp->line,
				"Syntax error in color line\n");
		else if (tmp->type == MAP_LINE && check_map_chars(tmp->line))
			clean_list_with_syntax_error(list, i, tmp->line,
				"Map should have only '01NSWE' chars inside the map\n");
		i++;
		tmp = tmp->next;
	}
	check_last_element(list);
}

// Ensures the last element in the linked list is a valid map line

void	check_last_element(t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	if (check_map_chars(tmp->line))
		clean_list_with_syntax_error(list, i, tmp->line,
			"Last line should be a map line\n");
}

// The function compares the first three chars of str against the directions:
// "NO " / "SO " / "WE " /"EA "
// Return (0) if OK, (1) if failed

int	check_directions_syntax(char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0
		|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Check if the str is for floor or ceiling colors
// Return (0) if OK, (1) if failed

int	check_color_syntax(char *str)
{
    if ((ft_strncmp(str, "F ", 2) != 0) && (ft_strncmp(str, "C ", 2) != 0))
        return (EXIT_FAILURE);
    str++;
    while (*str)
    {
        if (!ft_isdigit(*str) && *str != ' ' && *str != ',')
            return (EXIT_FAILURE);
        str++;
    }
    return (EXIT_SUCCESS);
}

// Check if string contains only valid map characters (0, 1, ' '(outside), '\0', 'N',
//	'S', 'W', 'E')
// Return (0) if OK, (1) if failed

int	check_map_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != '\0' && !is_direction_char(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}