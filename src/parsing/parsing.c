/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:57:09 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/24 17:56:17 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Parse the map.cub file
// Check the extension, open, syntax, dupplicates,
// values and fill data if correct to send to mlx.
// Return (nothing);

void	parsing(int argc, char **argv,  t_data **data)
{
	int     fd;
	t_list *list;

	fd = 0;
	list = NULL;
	check_argc(argc, argv);
    check_map_open(argv[1], &fd);
	create_map_in_list(fd, &list);
	check_map_syntax(&list);
	check_map_duplicates(&list);
	check_map_empty_lines(&list);
	check_map_close_fd(fd, list);
	initialize_data(data, &list);
	ft_lst_clear(&list);
	check_texture_extension(data);
	check_texture_open(data);
	count_players(data);
	check_map_is_closed(data);

	// for tests
	print_map(*data); // kill before push
	// print_map_copy(t_data *data) // kill before push
}

// kill before push

/* void	print_map_copy(t_data *data)
{
    int i;

    i = 0;
    while (i < data->map_height)
    {
        printf("%s\n", data->map[i]);
        i++;
    }
} */

void print_map(t_data *data)
{
    int i, j;
    printf("\nMap Dimensions: %d x %d\n", data->map_width, data->map_height);
    printf("Player Position: X = %d, Y = %d\n", data->player_x, data->player_y);
    printf("Facing Direction: %c\n\n", data->player_direction);

    for (i = 0; i < data->map_height; i++)
    {
        for (j = 0; data->map[i][j]; j++)
        {
            if (i == data->player_y && j == data->player_x)
            {
                printf("\033[5;31m%c\033[0m", data->player_direction);
            }
            else if (data->map[i][j] == '0')
            {
                printf(" ");
            }
            else if (data->map[i][j] == '1')
            {
                printf(".");
            }
            else
            {
                printf("%c", data->map[i][j]);
            }
        }
        printf("\n");
	}
printf("\n");
}