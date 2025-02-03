/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:42:41 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/03 16:55:19 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	initialize_data(t_data **data, t_list **list)
{
	init_data(data, list);
	fill_texture(data, list, &(*data)->north_texture, "NO ");
	fill_texture(data, list, &(*data)->south_texture, "SO ");
	fill_texture(data, list, &(*data)->west_texture, "WE ");
	fill_texture(data, list, &(*data)->east_texture, "EA ");
	if (!(*data)->north_texture || !(*data)->south_texture
		|| !(*data)->west_texture || !(*data)->east_texture)
	{
		clean_all_exit(data, list, "Error: One or more textures missing\n");
	}
	fill_colors(data, list, (*data)->floor_rgb, "F ");
	fill_colors(data, list, (*data)->ceiling_rgb, "C ");
	get_map_size(data, list);
	init_empty_map(data, list);
	fill_map(data, list);
	get_player_position(data);
}

void	init_data(t_data **data, t_list **list)
{
	*data = (t_data *)malloc(sizeof(t_data) * 1);
	if (!*data)
		clean_all_exit(data, list, "Data initialization failed\n");
	(*data)->map = NULL;
	(*data)->map_height = 0;
	(*data)->map_width = 0;
	(*data)->floor_rgb[0] = 0;
	(*data)->floor_rgb[1] = 0;
	(*data)->floor_rgb[2] = 0;
	(*data)->ceiling_rgb[0] = 0;
	(*data)->ceiling_rgb[1] = 0;
	(*data)->ceiling_rgb[2] = 0;
	(*data)->north_texture = NULL;
	(*data)->south_texture = NULL;
	(*data)->west_texture = NULL;
	(*data)->east_texture = NULL;
	(*data)->player_x = 0;
	(*data)->player_y = 0;
	(*data)->player_direction = '\0';
	(*data)->player_direction_radian = 0.0;
}
