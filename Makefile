COMPILER = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = cub3D

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

OBJS_DIR = obj

SRCS = index.c \
			parsing/parsing.c parsing/parse_textures.c parsing/get_color.c \
			parsing/parse_map.c parsing/parsing_utils.c \
			minimap/render_minimap.c minimap/move_on_minimap.c \
			hooks.c \
			free_memory.c \
			ray_calculations.c wall_calculations.c time_calculations.c \
			initialize_structs.c \
			movement_rotations.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm $(LIBFT)
# OTHER_DIRS = 

NO_COLOR = \033[0m
RED = \033[31m
GREEN = \033[32;5m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36;5m

all: $(LIBFT) $(NAME)

$(OBJ_DIR):
	@	mkdir -p $(OBJ_DIR)	--quiet

$(LIBFT):
	@	$(MAKE) -C $(LIBFT_DIR) --quiet

$(NAME): $(LIBFT) $(SRCS)
	@	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)Object files created!$(NO_COLOR)"

%.o: %.c
	@	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning...$(NO_COLOR)"
	@	rm -f $(OBJS)
	@	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@echo "$(RED)Full Cleaning...$(NO_COLOR)"
	@	rm -f $(NAME)
	@	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus