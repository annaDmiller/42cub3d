/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:57:09 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/07 13:04:10 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Parse the map.cub file
// Check the extension, open, syntax, dupplicates,
// values and fill data if correct to send to mlx.
// Return (nothing);

void	parsing(int argc, char **argv, t_data **data)
{
	int     fd;
	t_parse *list;

	fd = 0;
	list = NULL;
	check_argc(argc, argv);
    check_open(argv[1], &fd);
}