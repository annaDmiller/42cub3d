/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_close.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:09:16 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:12:47 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	close_error_texture_file(t_data **data, int *fd)
{
	close_all_textures(fd);
	if (fd[NORTH] == -1)
		clean_data_map_exit(data, 0, "Can't open North texture\n");
	if (fd[SOUTH] == -1)
		clean_data_map_exit(data, 0, "Can't open South texture\n");
	if (fd[WEST] == -1)
		clean_data_map_exit(data, 0, "Can't open West texture\n");
	if (fd[EAST] == -1)
		clean_data_map_exit(data, 0, "Can't open East texture\n");
}

void	close_all_textures(int *fd)
{
	if (fd[NORTH] != -1)
		close(fd[NORTH]);
	if (fd[SOUTH] != -1)
		close(fd[SOUTH]);
	if (fd[WEST] != -1)
		close(fd[WEST]);
	if (fd[EAST] != -1)
		close(fd[EAST]);
}

void	close_texture_files(t_data **data, int *fd)
{
	if (fd[NORTH] != -1)
	{
		close_all_textures(fd);
		clean_data_map_exit(data, 0, "North texture is directory\n");
	}
	if (fd[SOUTH] != -1)
	{
		close_all_textures(fd);
		clean_data_map_exit(data, 0, "South texture is directory\n");
	}
	if (fd[WEST] != -1)
	{
		close_all_textures(fd);
		clean_data_map_exit(data, 0, "West texture is directory\n");
	}
	if (fd[EAST] != -1)
	{
		close_all_textures(fd);
		clean_data_map_exit(data, 0, "East texture is directory\n");
	}
}
