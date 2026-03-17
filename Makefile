NAME = cub3D
NAME_BONUS = cub3D_bonus

INC_DIR = includes
CFLAGS = -Wall -Wextra -Werror -Ilibft -MMD -g -O3 -I$(INC_DIR)
OBJ_DIR = obj
LDFLAGS = -L/usr/lib -lmlx -lXext -lX11 -lm -lz

VPATH = src src/core src/init src/input src/parsing src/parsing/create_and_validate_map src/parsing/parse_info src/render \
        src_bonus src_bonus/core src_bonus/init src_bonus/input src_bonus/parsing src_bonus/parsing/create_and_validate_map src_bonus/parsing/parse_info src_bonus/render

SRC = main.c cleanup.c start_game.c init_data.c init_mlx.c key_hooks.c set_up_hooks.c valid_file.c \
      collision.c movement.c rotation.c parse_input.c read_file_to_string.c create_and_validate_map.c \
      create_map.c validate_map.c color_info.c parse_info.c wall_info.c raycaster.c s_atoi.c

SRC_BONUS = main_bonus.c cleanup_bonus.c start_game_bonus.c init_data_bonus.c init_mlx_bonus.c key_hooks_bonus.c \
            set_up_hooks_bonus.c valid_file_bonus.c collision_bonus.c movement_bonus.c rotation_bonus.c \
            parse_input_bonus.c read_file_to_string_bonus.c create_and_validate_map_bonus.c \
            create_map_bonus.c validate_map_bonus.c color_info_bonus.c parse_info_bonus.c wall_info_bonus.c raycaster_bonus.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP = $(SRC:%.c=$(OBJ_DIR)/%.d)

OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)
DEP_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)/%.d)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LDFLAGS)

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS) 
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS) $(LDFLAGS)

clean: 
	@rm -f $(OBJ) $(OBJ_BONUS) $(DEP) $(DEP_BONUS)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEP) $(DEP_BONUS)

.PHONY: all bonus clean fclean re