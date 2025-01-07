/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_duplicates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:08:01 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/07 17:44:28 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Checks the list for duplicate direction and color lines :
// dup[NORTH], dup[SOUTH], dup[WEST], dup[EAST], dup[FLOOR], dup[CEILING]

void	check_map_duplicates(t_list **list)
{
	t_list	*tmp;
	int		i;
	int		duplicates[6];

	tmp = *list;
	i = 0;
	set_tab_with_zero(duplicates, 6, 0);
	while (tmp)
	{
		if (tmp->type == TEXTURE_LINE)
			check_directions_duplicates(list, duplicates, tmp->line, i);
		if (tmp->type == COLOR_LINE)
			check_color_duplicates(list, duplicates, tmp->line, i);
		i++;
		tmp = tmp->next;
	}
	check_missing_lines(list, duplicates);
}

// Clears the dup array, setting all its elements to 0
// Retunr (nothing)

void	set_tab_with_zero(int *tab, int tab_size, int value)
{
	int	i;

	i = 0;
	while (i < tab_size)
	{
		tab[i] = value;
		i++;
	}
}

// Checks ifor any duplicate direction lines in the map
// Retunr (nothing)

void	check_directions_duplicates(t_list **list, int *duplicates, char *str,
		int i)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
	{
		duplicates[NORTH] += 1;
		if (duplicates[NORTH] > 1)
			clean_list_with_syntax_error(list, i, str,
				"Duplicates of North textures\n");
	}
	else if (ft_strncmp(str, "SO ", 3) == 0)
	{
		duplicates[SOUTH] += 1;
		if (duplicates[SOUTH] > 1)
			clean_list_with_syntax_error(list, i, str,
				"Duplicates of South textures\n");
	}
	else if (ft_strncmp(str, "WE ", 3) == 0)
	{
		duplicates[WEST] += 1;
		if (duplicates[WEST] > 1)
			clean_list_with_syntax_error(list, i, str,
				"Duplicates of West textures\n");
	}
	else if (ft_strncmp(str, "EA ", 3) == 0)
	{
		duplicates[EAST] += 1;
		if (duplicates[EAST] > 1)
			clean_list_with_syntax_error(list, i, str,
				"Duplicates of East textures\n");
	}
}

// Checks for any duplicate floor or ceiling color lines in the map
// Return (nothing)

void	check_color_duplicates(t_list **list, int *duplicates, char *str, int i)
{
	if (ft_strncmp(str, "F ", 2) == 0)
	{
		duplicates[FLOOR] += 1;
		if (duplicates[FLOOR] > 1)
			clean_list_with_syntax_error(list, i, str,
				"Duplicates of floor colors\n");
	}
	else if (ft_strncmp(str, "C ", 2) == 0)
	{
		duplicates[CEILING] += 1;
		if (duplicates[CEILING] > 1)
			clean_list_with_syntax_error(list, i, str,
				"Duplicates of ceiling colors\n");
	}
}

// Check if all required lines are present
// Return (nothing)

void	check_missing_lines(t_list **list, int *duplicates)
{
	if (duplicates[NORTH] == 0)
		clean_list(list, "North texture line is missing\n");
	else if (duplicates[SOUTH] == 0)
		clean_list(list, "South texture line is missing\n");
	else if (duplicates[WEST] == 0)
		clean_list(list, "West texture line is missing\n");
	else if (duplicates[EAST] == 0)
		clean_list(list, "East texture line is missing\n");
	else if (duplicates[FLOOR] == 0)
		clean_list(list, "Floor color line is missing\n");
	else if (duplicates[CEILING] == 0)
		clean_list(list, "Ceiling color line is missing\n");
}