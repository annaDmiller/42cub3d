# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 17:22:56 by okapshai          #+#    #+#              #
#    Updated: 2025/01/24 14:34:14 by okapshai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = cub3D

##############
# SRCS FILES #
##############

# DIRECTORY VARIABLES
SRCS_DIR            := src/
LIBFT_DIR           := src/libft/
MLX_DIR             := includes/minilibx-linux/

# SRCS VARIABLES
SRCS_FILES          := \
                    main.c \
                   	parsing/check_args.c \
                    parsing/parsing.c \
					parsing/check_map_open.c\
					parsing/create_map_in_list.c\
					parsing/check_map_syntax.c\
					parsing/cleaner.c\
					parsing/check_map_duplicates.c\
					parsing/check_map_empty_lines.c\
					parsing/check_map_close_fd.c\
					parsing/check_map_is_closed.c\
					parsing/count_players.c\
					parsing/init_data.c\
					parsing/check_texture_extension.c\
					parsing/get_map_size.c\
					parsing/init_empty_map.c\
					parsing/fill_map.c\
					parsing/get_player_position.c\
					parsing/check_texture_open.c\
					start_mlx/start_mlx.c\
					start_mlx/set_texture.c\
					start_mlx/clean_mlx.c \
					start_mlx/init_player.c  

SRCS_LIBFT          := $(wildcard $(LIBFT_DIR)*.c)
SRCS                := $(addprefix $(SRCS_DIR), $(SRCS_FILES))

###############
# INGREDIENTS #
###############

# INC
INC_DIR             := includes/
MLX_INC             := $(MLX_DIR)

# OBJS
OBJS_DIR            := objs/
OBJS                := $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_LIBFT          := $(SRCS_LIBFT:$(LIBFT_DIR)%.c=$(OBJS_DIR)libft/%.o)

# DEPENDENCIES
DEPS                := $(OBJS:$(OBJS_DIR)%.o=$(OBJS_DIR)%.d)

# FLAGS
CC                  := gcc
CFLAGS              := -Wall -Wextra -Werror -MMD -MP -g
INCFLAGS            := -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX_INC)
LX                  := $(MLX_DIR)libmlx.a
LIB                 := -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

# BASH FUNCTIONS
RM                  := rm -rf
DIR_DUP             := mkdir -p $(dir $@)

###########
# COLORS #
###########
GREEN = '\033[0;32m'
CYAN = '\033[0;36m'
WHITE = '\033[0;37m'

all: $(NAME)

$(NAME): $(LX) $(OBJS) $(OBJS_LIBFT)
	$(CC) $(CFLAGS) $(INCFLAGS) $(OBJS) $(OBJS_LIBFT) $(LX) $(LIB) -o $@
	@echo ✅ $(GREEN)"Project successfully compiled"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJS_DIR)libft/%.o: $(LIBFT_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(LX):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@echo 🧹 $(CYAN)"Cleaning up object files"$(WHITE)
	$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo 🧹 $(CYAN)"Removing all"$(WHITE)
	$(RM) $(NAME)
	$(RM) $(LX)

re: fclean all

.PHONY: all clean fclean re
