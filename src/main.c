/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:50:07 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/24 17:35:45 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	parsing(argc, argv, &data);
	start_mlx(data);
	//clean_all_function
	return (EXIT_SUCCESS);
}