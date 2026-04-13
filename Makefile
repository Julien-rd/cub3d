NAME = cub3D
NAME_BNS = cub3D_bonus
INC_DIR = includes
CFLAGS = -Wall -Wextra -Werror -Ilibft -MMD -g -I$(INC_DIR)
OBJ_DIR = obj
LDFLAGS = -L/usr/lib -lmlx -lXext -lX11 -lm -lz
VPATH = src bonus src/core src/init src/movement src/parsing \
	src/parsing/create_and_validate_map src/parsing/parse_info src/draw

SRC = main.c cleanup.c start_game.c init_data.c init_mlx.c key_hooks.c \
	set_up_hooks.c valid_file.c collision.c rotation.c \
	parse_input.c read_file_to_string.c create_and_validate_map.c \
	create_map.c validate_map.c color_info.c parse_info.c wall_info.c \
	s_atoi.c move_player.c init_ray.c draw_image.c init_camera.c \
	ft_put_pixel.c get_rays.c

SRC_BNS = main.c cleanup.c start_game_bonus.c init_data.c init_mlx.c key_hooks.c \
	set_up_hooks.c valid_file.c collision.c rotation.c \
	parse_input.c read_file_to_string.c create_and_validate_map.c \
	create_map.c validate_map.c color_info.c parse_info.c wall_info.c \
	s_atoi.c move_player.c init_ray.c minimap_bonus.c draw_image.c \
	init_camera.c ft_put_pixel.c draw_ray_bonus.c get_rays.c

OBJ = $(SRC:%.c=obj/%.o)
OBJ_BNS = $(SRC_BNS:%.c=obj/%.o)
DEP = $(SRC:%.c=obj/%.d)
DEP_BNS = $(SRC_BNS:%.c=obj/%.d)
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
	@rm -f $(OBJ) $(DEP) $(OBJ_BNS) $(DEP_BNS)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(LIBFT) $(OBJ_BNS)
	@$(CC) $(CFLAGS) $(OBJ_BNS) $(LIBFT) -o $(NAME_BNS) $(LDFLAGS)

-include $(DEP)

.PHONY: all clean fclean re bonus
