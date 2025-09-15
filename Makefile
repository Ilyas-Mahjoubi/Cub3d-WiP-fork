CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft -I minilibx-linux -g
NAME = cub3D
#NAME_BONUS = 
OBJ_DIR = obj

SRC_MAIN = main.c \
			parsing/parsing.c parsing/parse_textures.c parsing/get_color.c \
			parsing/parse_map.c parsing/parsing_utils.c \
			free_memory.c \

#SRC_BONUS = 

OBJECTS_MAIN = $(SRC_MAIN:%.c=$(OBJ_DIR)/%.o)
#OBJECTS_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)
OBJECTS = $(OBJECTS_MAIN)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR =  minilibx-linux
MINILIBX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -lm -lX11 -lXext

NO_COLOR = \033[0m
RED = \033[31m
GREEN = \033[32;5m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36;5m

all: $(LIBFT) $(MINILIBX) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX_DIR):
#	scarica archivio(.tgz)
	@curl https://cdn.intra.42.fr/document/document/26198/$(MLX_DIR).tgz --output $(MLX_DIR).tgz
#	tar = estrarre archivio
	@tar -xf $(MLX_DIR).tgz
	@rm $(MLX_DIR).tgz

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(MINILIBX):
	@$(MAKE) -C $(MLX_DIR) --quiet

$(NAME): $(LIBFT) $(MINILIBX) $(SRC_MAIN)
	$(CC) $(CFLAGS) $(SRC_MAIN) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Object files created!$(NO_COLOR)"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@	${CC} -c ${CFLAGS}  $< -g  -o $@
#bonus: $(LIBFT) $(NAME_BONUS)

#$(NAME_BONUS): $(LIBFT) $(SRC_BONUS)
#	$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) -o $(NAME_BONUS)
#	@echo "$(CYAN)Bonus compiled!$(NO_COLOR)"

clean:
	@echo "$(YELLOW)Cleaning...$(NO_COLOR)"
	@	$(MAKE) -C $(LIBFT_DIR) clean --quiet

fclean: clean
	@echo "$(RED)Full Cleaning...$(NO_COLOR)"
	@	rm -rf $(OBJ_DIR) $(NAME) $(NAME_BONUS)
	@	$(MAKE) -C $(LIBFT_DIR) fclean --quiet

re: fclean all

libft: $(LIBFT)
minilibx: $(MINILIBX)

.PHONY: all clean fclean re libft #bonus
