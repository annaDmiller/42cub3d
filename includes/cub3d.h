/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:35:44 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/07 12:42:27 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../includes/minilibx-linux/mlx.h"
# include "../src/libft/libft.h"
# include "../src/libft/get_next_line.h"


# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>


typedef struct s_data
{
	char	**map;
	int		map_height;
	int		map_width;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_rgb;
	int		ceiling_rgb;
	int		player_x;
	int		player_y;
	char	player_dir;
	float	player_dir_radian;
}          t_data;



// Linked list for map parsing

typedef struct s_parse
{
	char			*line;
	int				line_size;
	int				type;
	struct t_parse	*next;
}    		 t_parse;



/*PARSING*/

void	parsing(int argc, char **argv, t_data **data);
void	check_argc(int argc, char **argv);
int		check_extension(char *filename, char *extension);
void	print_exit_error(char *message);


#endif
