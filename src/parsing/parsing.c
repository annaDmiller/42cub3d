/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:57:09 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/20 11:48:05 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Parse the map.cub file
// Check the extension, open, syntax, dupplicates,
// values and fill data if correct to send to mlx.
// Return (nothing);

void	parsing(int argc, char **argv,  t_data **data)
{
	int     fd;
	t_list *list;

	fd = 0;
	list = NULL;
	check_argc(argc, argv);
    check_map_open(argv[1], &fd);
	create_map_in_list(fd, &list);
	check_map_syntax(&list);
	check_map_duplicates(&list);
	check_map_empty_lines(&list);
	check_map_close_fd(fd, list);
	initialize_data(data, &list);
	check_map_is_closed(data); // SEGFAULT i will check at my return
	check_texture_extensions(data);
}