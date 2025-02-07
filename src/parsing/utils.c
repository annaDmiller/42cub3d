/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:05:59 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:12:47 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	increment_texture_count(int *duplicates, int dir)
{
	duplicates[dir] += 1;
}

int	check_map_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != '\0'
			&& !is_direction_char(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	count_commas(char *str)
{
	int	comma_count;
	int	i;

	comma_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		i++;
	}
	return (comma_count);
}
