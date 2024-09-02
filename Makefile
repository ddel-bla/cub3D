# --------------------------------
# -------- MAIN VARIABLES --------
# --------------------------------

NAME	=	cub3d

CC		=	gcc
CFLAGS	=	-g -Wall -Wextra -Werror -I./include -I./lib/minilibx/
LDFLAGS =	-L./lib/libft -lft -L./lib/minilibx -lmlx -lX11 -lXext -lm

RM		=	rm -f

# ---------------------------------
# ---------- SRC & OBJS -----------
# ---------------------------------

SRC		=	./src/main.c \
			./src/init.c \
			./src/parse_map.c \
			./src/render.c \
			./src/events.c \
			./src/movement.c \
			./src/textures.c \
			./src/cleanup.c

OBJS	=	$(patsubst ./src/%.c, ./build/%.o, $(SRC))

# ---------------------------------
# ---------- LIBRARIES -----------
# ---------------------------------

# ............ LIBFT ..............
LIBFT	=	./lib/libft
LIBFT_A	=	$(LIBFT)/libft.a

# .......... MiniLibX .............
MLX		=	./lib/minilibx
MLX_A	=	$(MLX)/libmlx.a

# ---------------------------------
# --------- FLOWER POWER ----------
# ---------------------------------

PINK		=	\033[38;5;217m
TURQUOISE	=	\033[38;5;80m
YELLOW		=	\033[38;5;229m
RESET		=	\033[0m

START		=	"$(TURQUOISE)Compiling $(YELLOW) Cub3D...$(RESET)"
DONE		=	"$(TURQUOISE)Compilation $(YELLOW)complete!$(RESET)"
VALGRIND	=	"$(PINK)Running Valgrind...$(RESET)"
LEAKS		=	"$(TURQUOISE)[Leak Mode]$(RESET)"
DATA_RACES	=	"$(TURQUOISE)[Data Races Mode]$(RESET)"
CLEAN		=	"$(PINK)Cleaning $(YELLOW)files...$(RESET)"
CLEAN_DONE	=	"$(PINK)Clean $(TURQUOISE)complete!$(RESET)"

# ---------------------------------
# ------------ RULES --------------
# ---------------------------------
all			: $(NAME)

$(NAME)		: $(OBJS)
	@echo $(START)
	@make -C $(LIBFT) -f Makefile
	@make -C $(MLX) -f Makefile
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo $(DONE)

./build/%.o	: ./src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean		:
	@echo $(CLEAN)
	@make -C $(LIBFT) clean
	@make -C $(MLX) clean
	@$(RM) -r ./build
	@echo $(CLEAN_DONE)

fclean		: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(MLX) clean
	@$(RM) $(NAME)

leaks		: re
	@echo $(VALGRIND)
	@echo $(LEAKS)
	valgrind --leak-check=full --track-origins=yes -s ./$(NAME)

races		: re
	@echo $(VALGRIND)
	@echo $(DATA_RACES)
	valgrind --tool=helgrind ./$(NAME)

re			:	fclean all

.PHONY		: all fclean re clean leaks races
