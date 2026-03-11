NAME = cub3D
INC_DIR = includes
CFLAGS = -Wall -Wextra -Werror -Ilibft -MMD -g -I$(INC_DIR)
OBJ_DIR = obj
LDFLAGS = -L/usr/lib -lmlx -lXext -lX11 -lm -lz
VPATH = parsing parsing/create_and_validate_map \
parsing/parse_info helper key_hooks init
SRC = main.c parse_input.c read_file_to_string.c color_info.c parse_info.c \
wall_info.c create_and_validate_map.c validate_map.c create_map.c cleanup.c \
calculations.c key_hooks.c movement.c movement_helpers.c rotations.c \
init_data.c valid_file.c

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
