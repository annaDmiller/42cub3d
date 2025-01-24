/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:35:44 by okapshai          #+#    #+#             */
/*   Updated: 2025/01/24 17:40:22 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

# define WIDTH 1024
// # define WIDTH 683
# define HEIGHT 384

typedef struct s_data	t_data;
typedef struct s_mlx	t_mlx;
typedef struct s_img	t_img;
typedef struct s_list	t_list;

enum					e_player
{
	X,
	Y,
	X_PIXEL,
	Y_PIXEL,
	ANGLE,
	POSITION,
};

enum					e_type
{
	ERROR_TYPE = 0,
	EMPTY_LINE,
	TEXTURE_LINE,
	COLOR_LINE,
	MAP_LINE,
	ERROR_LINE,
};

enum					e_TextureAndColor
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING,
};

enum					e_RGB
{
	RED_RGB = 0,
	GREEN_RGB,
	BLUE_RGB,
};

enum					e_img
{
	WALL_NORTH,
	WALL_SOUTH,
	WALL_WEST,
	WALL_EAST,
	PLACEHOLDER,
	FLOOR_IMG,
	CEILING_IMG,
	IMG,
};

struct 			s_data
{
	char				**map;
	int					map_height;
	int					map_width;
	int					floor_colors;
	int					ceiling_colors;
	char				*north_texture;
	char				*south_texture;
	char				*west_texture;
	char				*east_texture;
	int					player_x;
	int					player_y;
	char				player_direction;
	float				player_direction_radian;
};

struct 			s_list
{
	char				*line;
	int					line_size;
	int					type;
	t_list				*next;
};

struct 			s_img
{
	void				*img;
	int					*address;
	int 				bits_per_pixel; // Color depth of the image : when using ARGB this value is always 32
	int					height;
	int					width;
	int 				line_length; // How many bytes each row of the image occupies : (your image width) * 4
	int 				endian;      //This value can be either 0 or 1 and will indicate how the ARGB bytes are organized (from front to back or back to front)
};


struct 			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_img				image[IMG];
	double				player[POSITION];
	double 				movement_vector[2]; // [0] = horizontal movement ,[1] = vertical movement
	t_data				*data;
};

/*PARSING*/
void					parsing(int argc, char **argv, t_data **data);
void					check_argc(int argc, char **argv);
int						check_extension(char *filename, char *extension);

void					print_error(char *message);
void					clean_list_gnl(t_list **list, char *line);
void					clean_list_with_syntax_error(t_list **list, int i,
							char *line, char *message);
void					clean_list(t_list **list, char *message);
void					clean_list_with_syntax_error(t_list **list, int i,
							char *line, char *message);
void					clean_data_map_exit(t_data **data, int i, char *msg);
void					clean_data(t_data **data);
void					free_array(char **arr);
void					clean_all_exit(t_data **data, t_list **list, char *msg);

void					create_map_in_list(int fd, t_list **list);
int						set_line_type(char *str);
int						is_direction_char(char c);
int						is_color_char(char c);
void					clean_list(t_list **list, char *message);
void					check_map_open(char *filename, int *fd);

void					check_map_syntax(t_list **list);
void					check_last_element(t_list **list);
int						check_directions_syntax(char *str);
int						check_color_syntax(char *str);
int						check_map_chars(char *str);

void					check_map_duplicates(t_list **list);
void					set_tab_with_zero(int *tab, int tab_size, int value);
void					check_directions_duplicates(t_list **list,
							int *duplicates, char *str, int i);
void					check_color_duplicates(t_list **list, int *dup,
							char *str, int i);
void					check_missing_lines(t_list **list, int *dup);

void					check_map_empty_lines(t_list **list);

int						check_map_close_fd(int fd, t_list *list);

void					check_map_is_closed(t_data **data);
int						check_close_chars(char *str);
void					check_first_last_char(t_data **data);
void					check_inside_map(t_data **data);
void					check_direction_side(t_data **data, int x, int y,
							int direction);
void					initialize_data(t_data **data, t_list **list);
void					init_data(t_data **data, t_list **list);
void					fill_texture(t_data **data, t_list **list, char **dest,
							char *src);
char					*trimmed_string(char *str, char *set);
void					fill_colors(t_data **data, t_list **list, int *dst,
							char *src);
int						rgb_in_hexa_value(t_data **data, t_list **list,
							char **str);
int						create_trgb_value(int t, int r, int g, int b);
int						check_rgb_syntax(char *str);
void					check_value_limits(t_data **data, t_list **list,
							char **array, char **str);
int						count_digits(char *str);
void					check_texture_extension(t_data **data);
void					get_map_size(t_data **data, t_list **list);
void					init_empty_map(t_data **data, t_list **list);
void					fill_map(t_data **data, t_list **list);
char					*copy_content(char *dest, char *src);
void					get_player_position(t_data **data);
int						direction_char(char c);
void					convert_dir_to_radian(t_data **data, char player_pos);
void					count_players(t_data **data);
void					check_texture_open(t_data **data);
void					check_if_texture_path_is_directory(t_data **data,
							int *fd, void *mlx);
void					close_texture_files(t_data **data, int *fd);
void					close_all_textures(int *fd);
int						check_texture_size(char *path, void *mlx);
void					clean_mlx_data_fd_exit(t_data **data, void *mlx,
							int *fd, char *msg);
void					close_error_texture_file(t_data **data, int *fd);
void					open_textures(t_data **data, int *fd, void *mlx);
void					print_map(t_data *data);
void					print_map_copy(t_data *data);

/*LIBFT*/

int						ft_atoi_base(char *str, int str_base);
int						ft_atoi(char *str);
int						ft_isdigit(char c);
void					ft_lst_clear(t_list **lst);
t_list					*ft_lstnew(char *line);
int						ft_lst_size(t_list *list);
t_list					*ft_lstadd_back(t_list **list, t_list *elem);
t_list					*ft_lstlast(t_list *list);
void					*ft_memset(void *b, int c, int len);
char					**ft_split(t_data **data, t_list **list, char *str,
							char c);
char					*ft_strchr(char *str, char c);
int						ft_strcmp(char *s1, char *s2);
int						ft_strlen(char *str);
int						ft_strncmp(char *s1, char *s2, unsigned int n);
char					*ft_strndup(char *str, int n);
int						get_next_line(int fd, char **line);
int						ft_putstr_fd(char *s, int fd);

/*MLX_INIT*/

void					start_mlx(t_data *data);
void					set_texture(t_mlx *mlx);
int						create_placeholder_image(void *mlx_ptr, t_img *img);
void					clean_mlx(t_mlx *mlx);
void					destroy_texture(t_mlx *mlx);
int						upload_texture(void *mlx_ptr, char *texture,
							t_img *img);
void					find_player(char **parsed_map, t_mlx *mlx);
void					init_player(t_mlx *mlx, int *position);
bool					is_player(char c, double *angle);




#endif
