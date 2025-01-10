/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_close_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:14:37 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/10 16:09:09 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Check if fd is properly closed

int	check_map_close_fd(int fd, t_list *list)
{
	int return_value;

	return_value = close(fd);
	if (return_value == -1)
		clean_list(&list, "Error closing the map file\n");
	return (EXIT_SUCCESS);
}