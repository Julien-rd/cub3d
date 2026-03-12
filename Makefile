NAME = cub3D
INC_DIR = includes
CFLAGS = -Wall -Wextra -Werror -Ilibft -MMD -g -I$(INC_DIR)
OBJ_DIR = obj
LDFLAGS = -L/usr/lib -lmlx -lXext -lX11 -lm -lz
VPATH = src src/core src/init src/input src/parsing src/parsing/create_and_validate_map src/parsing/parse_info src/render

SRC = main.c cleanup.c start_game.c init_data.c init_mlx.c key_hooks.c set_up_hooks.c valid_file.c \
      collision.c movement.c rotation.c parse_input.c read_file_to_string.c create_and_validate_map.c create_map.c validate_map.c \
      color_info.c parse_info.c wall_info.c raycaster.c

OBJ = $(SRC:%.c=obj/%.o)
DEP = $(SRC:%.c=obj/%.d)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD -MF $(@:.o=.d) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LDFLAGS)

clean: 
	@rm -f $(OBJ) $(DEP)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
