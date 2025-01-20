/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_extensions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:47:13 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/20 11:47:41 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    check_texture_extensions(t_data **data)
{
    if (check_extension((*data)->south_texture, ".xpm")
        || check_extension((*data)->north_texture, ".xpm")
        || check_extension((*data)->west_texture, ".xpm")
        || check_extension((*data)->east_texture, ".xpm"))
        return (clean_data_map_exit(data, 0, "Textures must have .xpm extension\n"));
    return ;
}