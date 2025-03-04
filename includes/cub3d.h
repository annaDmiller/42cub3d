/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:35:44 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 11:04:23 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <fcntl.h>
# define __USE_XOPEN
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
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

# define SCREEN_WIDTH 1100
# define SCREEN_HEIGHT 750
# define PLAYER_SIGHT 60
# define CELL_SIZE 64
# define MOV_SPEED 8
# define ROT_SPEED 0.05

# define ESCAPE 65307
# define A_KEY 97
# define S_KEY 115
# define W_KEY 119
# define D_KEY 100
# define LEFT 65361
# define RIGHT 65363

enum				e_player
{
	X,
	Y,
	X_PIXEL,
	Y_PIXEL,
	ANGLE,
	SIGHT,
	POSITION,
};

enum				e_type
{
	ERROR_TYPE = 0,
	EMPTY_LINE,
	TEXTURE_LINE,
	COLOR_LINE,
	MAP_LINE,
	ERROR_LINE,
};

enum				e_TextureAndColor
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING,
};

enum				e_RGB
{
	RED_RGB = 0,
	GREEN_RGB,
	BLUE_RGB,
};

enum				e_img
{
	WALL_NORTH,
	WALL_SOUTH,
	WALL_WEST,
	WALL_EAST,
	PLACEHOLDER,
	IMG,
};

typedef struct s_data
{
	char			**map;
	int				map_height;
	int				map_width;
	int				floor_rgb[3];
	int				ceiling_rgb[3];
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	int				player_x;
	int				player_y;
	char			player_direction;
	float			player_direction_radian;
}					t_data;

typedef struct s_list
{
	char			*line;
	int				line_size;
	int				type;
	struct s_list	*next;
}					t_list;

typedef struct s_ray
{
	double			angle;
	float			dist;
	int				hit_vert_wall;
	float			wall_hit_x;
	float			wall_hit_y;
	float			wall_height;
}					t_ray;

typedef struct s_img
{
	void			*img;
	int				*address;
	int				bits_per_pixel;
	int				height;
	int				width;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_ray			*ray;
	t_data			*map;
	t_img			image[IMG];
	double			player[POSITION];
	double			movement_vector[2];
}					t_mlx;

typedef struct s_player
{
	int				pos_x_pix;
	int				pos_y_pix;
	double			angle;
	double			sight_rad;
}					t_player;

/*PARSING*/
void				parsing(int argc, char **argv, t_data **data);
void				check_argc(int argc, char **argv);
int					check_extension(char *filename, char *extension);
char				*remove_spaces_and_tabs(char *str);
void				print_error(char *message);
void				clean_list_gnl(t_list **list, char *line);
void				clean_data_map_exit(t_data **data, int i, char *msg);
void				clean_data(t_data **data);
void				free_array(char **arr);
void				clean_all_exit(t_data **data, t_list **list, char *msg);
void				create_map_in_list(int fd, t_list **list);
int					set_line_type(char *str);
int					is_direction_char(char c);
int					is_color_char(char c);
void				clean_list_with_syntax_error(t_list **list, int i,
						char *line, char *message);
void				clean_list(t_list **list, char *message);
void				check_map_open(char *filename, int *fd);
void				increment_texture_count(int *duplicates, int dir);
void				check_map_syntax(t_list **list);
void				check_last_element(t_list **list);
int					check_directions_syntax(char *str);
int					check_color_syntax(char *str);
int					check_map_chars(char *str);
int					check_wall(t_mlx *mlx, double new_pos[2]);
void				calculate_movement_vector(t_mlx *mlx, double dist[2]);
void				set_new_position(t_mlx *mlx, char move, double new_pos[2],
						double dist[2]);
void				players_movement(t_mlx *mlx, char move);
void				check_map_duplicates(t_list **list);
void				set_tab_with_zero(int *tab, int tab_size, int value);
void				check_directions_duplicates(t_list **list, int *duplicates,
						char *str, int i);
void				check_color_duplicates(t_list **list, int *dup, char *str,
						int i);
void				check_missing_lines(t_list **list, int *dup);
int					count_commas(char *str);
void				check_map_empty_lines(t_list **list);
int					check_map_close_fd(int fd, t_list *list);
void				check_map_is_closed(t_data **data);
int					check_close_chars(char *str);
void				initialize_data(t_data **data, t_list **list);
void				init_data(t_data **data, t_list **list);
void				fill_texture(t_data **data, t_list **list, char **dest,
						char *src);
char				*trimmed_string(char *str, char *set);
void				fill_colors(t_data **data, t_list **list, int *dst_rgb,
						char *src);
int					get_rgb_value(t_data **data, t_list **list, char **str,
						int *dst_rgb);
void				check_value_limits(t_data **data, t_list **list,
						char **array, char **str);
int					count_digits(char *str);
void				check_texture_extension(t_data **data);
void				get_map_size(t_data **data, t_list **list);
void				init_empty_map(t_data **data, t_list **list);
void				fill_map(t_data **data, t_list **list);
char				*copy_content(char *dest, char *src);
void				get_player_position(t_data **data);
int					direction_char(char c);
void				convert_dir_to_radian(t_data **data, char player_pos);
void				count_players(t_data **data);
void				check_texture_open(t_data **data);
void				check_if_texture_path_is_directory(t_data **data, int *fd,
						void *mlx);
void				close_texture_files(t_data **data, int *fd);
void				close_all_textures(int *fd);
void				clean_mlx_data_fd_exit(t_data **data, void *mlx, int *fd,
						char *msg);
void				close_error_texture_file(t_data **data, int *fd);
void				open_textures(t_data **data, int *fd, void *mlx);
int					handle_keypress(int keycode, t_mlx *mlx);
int					handle_close(t_mlx *mlx);
void				check_map_is_closed(t_data **data);
void				free_map_copy(char **temp_map, int height);
void				find_start_point(char **map, t_data *data, int *start_x,
						int *start_y);
char				**copy_map(t_data *data);
void				flood_fill(char **map, int x, int y, t_data *data);
int					is_out_of_bounds(int x, int y, t_data *data);

/*LIBFT*/

int					ft_atoi_base(char *str, int str_base);
int					ft_atoi(char *str);
int					ft_isdigit(char c);
void				ft_lst_clear(t_list **lst);
t_list				*ft_lstnew(char *line);
int					ft_lst_size(t_list *list);
t_list				*ft_lstadd_back(t_list **list, t_list *elem);
t_list				*ft_lstlast(t_list *list);
void				*ft_memset(void *b, int c, int len);
char				**ft_split(t_data **data, t_list **list, char *str, char c);
char				*ft_strchr(char *str, char c);
int					ft_strcmp(char *s1, char *s2);
int					ft_strlen(char *str);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
char				*ft_strndup(char *str, int n);
int					get_next_line(int fd, char **line);
int					ft_putstr_fd(char *s, int fd);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_strdup(char *src);

/*MLX_INIT*/
int					mlx_init_struct(t_mlx *mlx);
void				start_mlx(t_data *data);
void				set_texture(t_mlx *mlx);
int					create_placeholder_image(void *mlx_ptr, t_img *img);
void				clean_mlx(t_mlx *mlx);
void				destroy_texture(t_mlx *mlx);
int					upload_texture(void *mlx_ptr, char *texture, t_img *img);
void				find_player(char **parsed_map, t_mlx *mlx);
void				init_player(t_mlx *mlx, int *position);
bool				is_player(char c, double *angle);

// RAY_CASTING
double				norming_angle(double angle);
void				ray_casting(t_mlx *mlx);
float				find_horiz_intersection(t_mlx *mlx, double angle);
float				find_vert_intersection(t_mlx *mlx, double angle);
void				draw_line(t_mlx *mlx, int screen_line);
void				render_floor_ceiling(t_mlx *mlx);
void				put_pix_to_img(t_mlx *mlx, int x, int y, int color);
void				paint_wall(t_mlx *mlx, int x_img, float wall_bot_pxl,
						float wall_top_pxl);
int					trgb(int t, int r, int g, int b);
int					get_color(int x, int y, t_img *texture);
void				find_wall_hit_point(t_mlx *mlx);
#endif
