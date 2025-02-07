/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_open.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:52:05 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:12:47 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_texture_open(t_data **data)
{
	void	*mlx;
	int		fd[4];

	set_tab_with_zero(fd, 4, 0);
	mlx = mlx_init();
	if (!mlx)
		clean_data_map_exit(data, 0, "What is wrong with you, pal?\n");
	check_if_texture_path_is_directory(data, fd, mlx);
	set_tab_with_zero(fd, 4, 0);
	open_textures(data, fd, mlx);
	close_all_textures(fd);
	mlx_destroy_display(mlx);
	free(mlx);
}

void	check_if_texture_path_is_directory(t_data **data, int *fd, void *mlx)
{
	fd[NORTH] = open((*data)->north_texture, __O_DIRECTORY | O_RDONLY);
	fd[SOUTH] = open((*data)->south_texture, __O_DIRECTORY | O_RDONLY);
	fd[WEST] = open((*data)->west_texture, __O_DIRECTORY | O_RDONLY);
	fd[EAST] = open((*data)->east_texture, __O_DIRECTORY | O_RDONLY);
	if (fd[NORTH] != -1 || fd[SOUTH] != -1 || fd[WEST] != -1 || fd[EAST] != -1)
	{
		mlx_destroy_display(mlx);
		close_texture_files(data, fd);
		free(mlx);
		clean_data_map_exit(data, 0, "Texture path is a directory\n");
	}
}

void	open_textures(t_data **data, int *fd, void *mlx)
{
	fd[NORTH] = open((*data)->north_texture, O_RDONLY);
	fd[SOUTH] = open((*data)->south_texture, O_RDONLY);
	fd[WEST] = open((*data)->west_texture, O_RDONLY);
	fd[EAST] = open((*data)->east_texture, O_RDONLY);
	if (fd[NORTH] == -1 || fd[SOUTH] == -1 || fd[WEST] == -1 || fd[EAST] == -1)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		close_error_texture_file(data, fd);
	}
}
