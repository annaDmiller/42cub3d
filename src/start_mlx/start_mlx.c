/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olly <olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:08:15 by olly              #+#    #+#             */
/*   Updated: 2025/01/26 12:54:44 by olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// initializing the mlx window, setting up texture


void	start_mlx(t_data *data)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	mlx.map = data;
	find_player(data->map, &mlx);
	set_texture(&mlx);
	if (!mlx.mlx_ptr)
		return;
	
}