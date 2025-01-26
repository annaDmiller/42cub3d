/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olly <olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:08:15 by olly              #+#    #+#             */
/*   Updated: 2025/01/26 18:19:39 by olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Initializes the mlx window and hooks the keypress and close events

void	start_mlx(t_data *data)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	mlx.map = data;
	find_player(data->map, &mlx);
	set_texture(&mlx);
	if (!mlx.mlx_ptr)
		return;
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, handle_keypress, &mlx);
	mlx_hook(mlx.win_ptr, ClientMessage, StructureNotifyMask, handle_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
