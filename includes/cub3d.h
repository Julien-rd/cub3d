/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:18:23 by jromann           #+#    #+#             */
/*   Updated: 2026/03/16 16:36:53 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FOV_LEN 0.66
# define WALL 49
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

# define FLOOR 0
# define CEILING 1
# define NO 2
# define SO 3
# define WE 4
# define EA 5

# define SUCCESS 0
# define ERROR 1
# define PERROR 2

# define MOVE_S 0.05
# define ROT_S 0.02

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ARR_R 65363
# define KEY_ARR_L 65361

//*************** CORE **************//

// exit_game
void	exit_game(t_user *user, int flag, char *msg);
void	cleanup_mlx(t_user *user);
void	free2d(char **str);

// start_game
void	start_game(t_user *user);
int		game_loop(t_user *user);

//*************** INIT **************//

// init_data
void	init_data(t_user *user);

// init_mlx
void	init_graphics(t_user *user);

// key_hooks
int		close_hook(t_user *user);
int		mouse_hook(int x, int y, t_user *user);
int		mouse_left_win_hook(t_user *user);
int		key_release_hook(int keycode, t_user *user);
int		key_press_hook(int keycode, t_user *user);

// set_up_hooks
void	set_up_hooks(t_user *user);

// valid_file
void	validate_file_extension(char *file_name);

//*************** INPUT **************//

// collision
bool	check_collision(t_user *user, double x, double y);

// movement
void	move_player(t_user *user);

// rotation
void	rotate_left(t_user *user);
void	rotate_right(t_user *user);

//*************** PARSING **************//

// create_and_validate_map/create_and_validate_map
void	create_and_validate_map(char *input, t_user *user);

// create_and_validate_map/create_map
size_t	map_exists(char *input, t_user *user);
void	check_empty_lines(char *map, char *input, t_user *user);

// create_and_validate_map/validate_map
void	valid_map(t_user *user);

// parse_info/color_info
void	color_info(t_user *user, char flag, size_t pos);

// parse_info/parse_info
void	parse_info(t_user *user);
size_t	skip_spaces(char *str);
int		s_atoi(const char *str);

// parse_info/wall_info
void	extract_line(t_user *user, size_t pos);
void	check_extensions(t_user *user, char *path);

// parse_input
int		parse_input(char *file_name, t_user *user);

// read_file_to_string
char	*read_file_to_string(char *file_name);

//*************** RENDER **************//

// raycaster
void	draw_ray(t_user *user);

#endif
