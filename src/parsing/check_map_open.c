/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:54:38 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/07 17:52:08 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Trying to open file as a directory: if succes, print exit error
// Trying to open file normally: if failed, print exit error
// Return (nothing), exit if failed

void	check_map_open(char *filename, int *fd)
{
	*fd = open(filename, __O_DIRECTORY | O_RDONLY);
	if (*fd != -1)
	{
		close(*fd);
		print_error("Map is  directory and not a file\n");
	}
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		print_error("Can not open map file\n");
}