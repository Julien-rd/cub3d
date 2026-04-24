ifeq ($(BONUS),1)
NAME = cub3D_bonus
else
NAME = cub3D
endif
NAME_BNS = cub3D_bonus
INC_DIR = includes
CFLAGS = -Wall -Wextra -Werror -Ilibft -MMD -g -I$(INC_DIR)
OBJ_DIR = obj
# LDFLAGS = -L/usr/lib -lmlx -lXext -lX11 -lm -lz 
LDFLAGS = -L/usr/local/lib -L/opt/X11/lib -lmlx -lXext -lX11 -lm -lz
VPATH = src src/core src/init src/movement src/parsing \
	src/parsing/create_and_validate_map src/parsing/parse_info src/render

SRC = main.c cleanup.c init_data.c init_mlx.c key_hooks.c \
	set_up_hooks.c valid_file.c collision.c rotation.c \
	parse_input.c read_file_to_string.c create_and_validate_map.c \
	create_map.c validate_map.c color_info.c parse_info.c wall_info.c \
	s_atoi.c init_ray.c draw_image.c \
	ft_put_pixel.c get_rays.c

ifeq ($(BONUS),1)
	SRC += start_game_bonus.c
	SRC += minimap_bonus.c
	SRC += draw_ray_bonus.c
	SRC += init_camera_bonus.c
	SRC += move_player_bonus.c
else
	SRC += start_game.c
	SRC += move_player.c
endif

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
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME) $(NAME_BNS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

bonus:
	@$(MAKE) --no-print-directory BONUS=1 all

-include $(DEP)

.PHONY: all clean fclean re bonus
