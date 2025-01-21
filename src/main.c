/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:50:07 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/21 13:26:13 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	parsing(argc, argv, &data);
	return (EXIT_SUCCESS);
}


/* int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "O&A Dynamics");
	(void)win;
    mlx_loop(mlx);
	sleep(5);
	mlx_destroy_display(mlx);
} */