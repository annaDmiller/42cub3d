/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_open.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:52:05 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/03 16:33:48 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	}
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

int	check_texture_size(char *path, void *mlx)
{
	void	*image;
	int		width;
	int		height;

	image = NULL;
	width = 0;
	height = 0;
	image = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!image || width != 64 || height != 64)
	{
		mlx_destroy_image(mlx, image);
		return (EXIT_FAILURE);
	}
	mlx_destroy_image(mlx, image);
	return (EXIT_SUCCESS);
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
		close_error_texture_file(data, fd);
	}
}

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
