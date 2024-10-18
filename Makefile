# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeliz-r <cfeliz-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 20:24:57 by ddel-bla          #+#    #+#              #
#    Updated: 2024/10/18 15:47:55 by cfeliz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR DEFINITION #
GREEN   = \033[0;92m
YELLOW  = \033[0;93m
BLUE    = \033[0;34m
RESET   = \033[0m

# Source and object files
SRCS    =  ./src/main.c \
           ./src/init.c \
           ./src/parse_map.c \
           ./src/render_dda.c \
		   ./src/render_ray.c \
           ./src/render_walls.c \
		   ./src/parse_aux.c \
		   ./src/parse_utils.c \
           ./src/render.c \
           ./src/events.c \
           ./src/movement.c \
           ./src/textures.c \
           ./src/cleanup.c \
		   ./src/draw_minimap.c
OBJS    = $(SRCS:.c=.o)

# Executable name
NAME    = cub3D

# Compiler and flags
CC      = gcc
INCLUDE = -L ./lib/libft -lft -L ./lib/minilibx -lmlx_Linux -lX11 -lXext -lm
DEBUG   = -fsanitize=address
CFLAGS  = -Wall -Werror -Wextra -g3 -fsanitize=address

# Clean command
RM      = rm -f

# Rule to compile .c files into .o files
.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling: $< $(RESET)"

# Main rule to link object files into the final executable
$(NAME): $(OBJS)
	make -C ./lib/libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)
	@echo "$(BLUE)cub3d - Compiled!$(RESET)"

# Default rule
all: $(NAME)


# Debug rule with address sanitizer
debug: CFLAGS += $(DEBUG)
debug: all

# Clean object files
clean:
	$(RM) $(OBJS)
	@echo "$(BLUE)cub3d - Object files cleaned!$(RESET)"

# Clean object and executable files
fclean: clean
	$(RM) $(NAME)
	@make -C ./lib/libft fclean
	@echo "$(BLUE)cub3d - Executable files cleaned!$(RESET)"

# Recompile everything
re: fclean all

.PHONY: all re clean fclean debug
