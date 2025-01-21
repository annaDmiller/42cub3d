/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_extension.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:47:13 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/21 13:27:34 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    check_texture_extension(t_data **data)
{
    if (check_extension((*data)->south_texture, ".xpm"))
        clean_data_map_exit(data, 0, "South texture must have .xpm extension\n");
    else if (check_extension((*data)->north_texture, ".xpm"))
        clean_data_map_exit(data, 0, "North texture must have .xpm extension\n");
    else if (check_extension((*data)->west_texture, ".xpm"))
        clean_data_map_exit(data, 0, "West texture must have .xpm extension\n");
    else if (check_extension((*data)->east_texture, ".xpm"))
        clean_data_map_exit(data, 0, "East texture must have .xpm extension\n");
}