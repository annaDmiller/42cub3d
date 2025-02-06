/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:50:07 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/06 18:38:14 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	parsing(argc, argv, &data);
	start_mlx(data);
	clean_data(&data);
	return (EXIT_SUCCESS);
}
