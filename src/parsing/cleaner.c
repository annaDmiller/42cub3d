/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:31:52 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/06 18:09:23 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_list(t_list **list, char *message)
{
	ft_lst_clear(list);
	print_error(message);
}

void	clean_list_with_syntax_error(t_list **list, int i, char *line,
		char *message)
{
	printf("[%d] " RED "[%s]" RESET "\n", i, line);
	ft_lst_clear(list);
	print_error(message);
}

void	clean_data_map_exit(t_data **data, int i, char *msg)
{
	int	j;

	j = 0;
	write(2, "Error\n", 6);
	printf("%s", msg);
	if (i != 0)
	{
		while (j < (*data)->map_height)
		{
			if ((j == i - 1) && (i - 1 > 0))
				printf("[%d] " YELLOW "[%s]" RESET "\n", j, (*data)->map[i
					- 1]);
			else if (j == i)
				printf("[%d] " RED "[%s]" RESET "\n", j, (*data)->map[i]);
			else if ((j == i + 1) && (i + 1 < (*data)->map_height))
				printf("[%d] " YELLOW "[%s]" RESET "\n", j, (*data)->map[i
					+ 1]);
			else
				printf("[%d] [%s]\n", j, (*data)->map[j]);
			j++;
		}
	}
	clean_data(data);
	exit(EXIT_FAILURE);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_map_copy(char **temp_map, int height)
{
	int	i;

	if (!temp_map)
		return;
	i = 0;
	while (i < height)
	{
		free(temp_map[i]);
		i++;
	}
	free(temp_map);
}
