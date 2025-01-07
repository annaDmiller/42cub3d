/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:35:44 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/07 15:43:55 by okapshai         ###   ########.fr       */
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

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

// Defines possible types for each line in the linked list
enum	e_type
{
	ERROR_TYPE = 0,
	EMPTY_LINE,
	TEXTURE_LINE,
	COLOR_LINE,
	MAP_LINE,
	ERROR_LINE,
};

typedef struct s_data
{
	char	**map;
	int		map_height;
	int		map_width;
}          t_data;



/*PARSING*/

void	parsing(int argc, char **argv/* , t_data **data */);
void	check_argc(int argc, char **argv);
int		check_extension(char *filename, char *extension);

void	print_error(char *message);
void	clean_list(t_list **list, char *line);
void	clean_list_with_syntax_error(t_list **list, int i, char *line, char *message);

void	create_list(int fd, t_list **list);
int		set_line_type(char *str);
int		is_direction_char(char c);
int		is_color_char(char c);

void	check_open(char *filename, int *fd);

void	check_list_syntax(t_list **list);
void	check_last_element(t_list **list);
int		check_directions_syntax(char *str);
int		check_color_syntax(char *str);
int		check_map_chars(char *str);

#endif
