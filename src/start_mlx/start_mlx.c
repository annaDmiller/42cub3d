/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:08:15 by olly              #+#    #+#             */
/*   Updated: 2025/02/03 16:12:43 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	start_mlx(t_data *data)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	mlx.map = data;
	find_player(data->map, &mlx);
	set_texture(&mlx);
	if (!mlx.mlx_ptr)
		return ;
	if (mlx_init_struct(&mlx) == -1)
		return ;
	ray_casting(&mlx);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, handle_keypress, &mlx);
	mlx_hook(mlx.win_ptr, ClientMessage, StructureNotifyMask, handle_close,
		&mlx);
	mlx_loop(mlx.mlx_ptr);
	return ;
}

int	mlx_init_struct(t_mlx *mlx)
{
	mlx->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!mlx->ray)
		return (-1);
	mlx->ray->angle = 0;
	mlx->ray->dist = 0;
	mlx->ray->hit_vert_wall = 0;
	mlx->ray->wall_height = 0;
	mlx->ray->wall_hit_x = 0;
	mlx->ray->wall_hit_y = 0;
	return (0);
}
