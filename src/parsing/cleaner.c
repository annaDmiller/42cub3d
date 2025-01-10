/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:31:52 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/10 16:10:36 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Prints an error message to STDERR and exits the program
// Exit (1) on failure

void	print_error(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

// clean linked list if GNL fails in lined list creation

void	clean_list_gnl(t_list **list, char *line)
{
	ft_lst_clear(list);
	free(line);
	print_error("GNL failed\n");
}

void	clean_list(t_list **list, char *message)
{
	ft_lst_clear(list);
	print_error(message);
}

// [3] [Invalid line content here]

void	clean_list_with_syntax_error(t_list **list, int i, char *line,
		char *message)
{
	printf("[%d] " RED "[%s]" RESET "\n", i, line);
	ft_lst_clear(list);
	print_error(message);
}

// Cleans up memory, displays an error message,
//	exits when the map is not enclosed

void	clean_data_map_exit(t_data **data, int i, char *msg)
{
	int	j;

	j = 0;
	write(2, "Error\n", 6);
	printf("%s", msg);
	while (j < (*data)->map_height)
	{
		if ((j == i - 1) && (i - 1 > 0))
			printf("[%d] " YELLOW "[%s]" RESET "\n", j, (*data)->map[i - 1]);
		else if (j == i)
			printf("[%d] " RED "[%s]" RESET "\n", j, (*data)->map[i]);
		else if ((j == i + 1) && (i + 1 < (*data)->map_height))
			printf("[%d] " YELLOW "[%s]" RESET "\n", j, (*data)->map[i + 1]);
		else
			printf("[%d] [%s]\n", j, (*data)->map[j]);
		j++;
	}
	clean_data(data);
	exit(EXIT_FAILURE);
}

void	clean_data(t_data **data)
{
	if (!*data)
		return ;
	if ((*data)->map)
		free_array((*data)->map);
	free((*data)->north_texture);
	free((*data)->south_texture);
	free((*data)->west_texture);
	free((*data)->east_texture);
	free(*data);
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

void	clean_all_exit(t_data **data, t_list **list, char *msg)
{
	if (*list)
		ft_lst_clear(list);
	if (data)
		clean_data(data);
	print_error(msg);
}