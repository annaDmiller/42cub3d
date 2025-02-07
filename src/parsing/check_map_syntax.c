/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:23:35 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:12:47 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	handle_syntax_errors(t_list **list, int i, t_list *tmp)
{
	if (tmp->type == ERROR_LINE)
		clean_list_with_syntax_error(list, i, tmp->line,
			"Syntax error in map file\n");
	else if (tmp->type == TEXTURE_LINE && check_directions_syntax(tmp->line))
		clean_list_with_syntax_error(list, i, tmp->line,
			"Syntax error in texture line\n");
	else if (tmp->type == COLOR_LINE && check_color_syntax(tmp->line))
		clean_list_with_syntax_error(list, i, tmp->line,
			"Syntax error in color line\n");
	else if (tmp->type == MAP_LINE && check_map_chars(tmp->line))
		clean_list_with_syntax_error(list, i, tmp->line,
			"Map should have only '01NSWE' chars inside the map\n");
}

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
		handle_syntax_errors(list, i, tmp);
		i++;
		tmp = tmp->next;
	}
	check_last_element(list);
}

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

int	check_directions_syntax(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0
		|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	check_color_syntax(char *str)
{
	int	comma_count;

	comma_count = count_commas(str);
	if (comma_count != 2)
	{
		ft_putstr_fd("Error: Invalid color syntax, too many commas\n", 2);
		return (EXIT_FAILURE);
	}
	while (*str == ' ' || *str == '\t')
		str++;
	if ((ft_strncmp(str, "F ", 2) != 0) && (ft_strncmp(str, "C ", 2) != 0))
		return (EXIT_FAILURE);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != ' ' && *str != '\t' && *str != ',')
			return (EXIT_FAILURE);
		str++;
	}
	return (EXIT_SUCCESS);
}
