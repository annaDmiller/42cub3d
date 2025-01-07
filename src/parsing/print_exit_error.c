/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exit_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:08:03 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/07 12:19:17 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Prints an error message to STDERR and exits the program
// Exit (1) on failure

void	print_exit_error(char *message)
{
	write(2, "Error\n", 6);
	printf("%s", message);
	exit(EXIT_FAILURE);
}