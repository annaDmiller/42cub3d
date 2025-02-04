/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:05:59 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/04 13:07:19 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

