/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:31:52 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/07 17:35:41 by okapshai         ###   ########.fr       */
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

void	clean_list_with_syntax_error(t_list **list, int i, char *line, char *message)
{
	printf("[%d] " RED "[%s]" RESET"\n", i, line);
	ft_lst_clear(list);
	print_error(message);
}