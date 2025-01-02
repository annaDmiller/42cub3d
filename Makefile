# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 17:22:56 by okapshai          #+#    #+#              #
#    Updated: 2025/01/02 18:12:47 by okapshai         ###   ########.fr        #
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
                    main.c
SRCS                := $(addprefix $(SRCS_DIR), $(SRCS_FILES))
SRCS_LIBFT          := $(wildcard $(LIBFT_DIR)*.c)

###############
# INGREDIENTS #
###############

# INC
INC_DIR             := includes/
LIBFT_INC           := $(LIBFT_DIR)
MLX_INC             := $(MLX_DIR)

# OBJS
OBJS_DIR            := objs/
OBJS                := $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_LIBFT          := $(SRCS_LIBFT:$(LIBFT_DIR)%.c=$(OBJS_DIR)libft/%.o)

# DEPENDENCIES
DEPS                := $(OBJS:$(OBJS_DIR)%.o=$(OBJS_DIR)%.d)

# FLAGS
CC                  := gcc
CFLAGS              := -Wall -Wextra -Werror -MMD -MP
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

-include $(DEPS)

clean:
	@echo 🧹 $(CYAN)"Removing .o files"$(WHITE)
	$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo 🧹 $(CYAN)"Removing all"$(WHITE)
	$(RM) $(NAME)
	$(RM) $(LX)

re: fclean all

.PHONY: all clean fclean re