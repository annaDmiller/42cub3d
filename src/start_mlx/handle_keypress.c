/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olly <olly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:18:29 by olly              #+#    #+#             */
/*   Updated: 2025/01/26 18:23:45 by olly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Handles the keypress event

int	handle_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		clean_mlx(mlx);
		exit(0);
	}
	// TO ADD other keypresses
	// mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	return (0);
}

int	handle_close(t_mlx *mlx)
{
	clean_mlx(mlx);
	exit(0);
	return (0);
}