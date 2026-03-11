/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:21:15 by jromann           #+#    #+#             */
/*   Updated: 2026/03/11 13:04:50 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	open_window(t_user *user)
{
	user->mlx = mlx_init();
	if (!user->mlx)
		cleanup(user, ERROR, "Error\nmlx_init failed\n");
	user->mlx_win = mlx_new_window(user->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cub3D");
	if (!user->mlx_win)
		cleanup(user, ERROR, "Error\nmlx_new_window failed\n");
	user->img = mlx_new_image(user->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!user->img)
		cleanup(user, ERROR, "Error\nmlx_new_img failed\n");
	user->image.img_data = mlx_get_data_addr(user->img, &user->image.bpp,
			&user->image.size_line, &user->image.endian);
	if (!user->image.img_data)
		cleanup(user, ERROR, "Error\nmlx_get_data_addr nofailed\n");
}

static void	load_textures(t_user *user)
{
	int	width;
	int	height;

	user->n_tex.img = mlx_xpm_file_to_image(user->mlx, user->no_path, &width,
			&height);
	if (!user->n_tex.img)
		cleanup(user, ERROR, "Error\nFailed to load north texture\n");
	user->n_tex.data = mlx_get_data_addr(user->n_tex.img, &user->n_tex.bpp,
			&user->n_tex.line_len, &user->n_tex.endian);
	user->n_tex.width = width;
	user->n_tex.height = height;
	user->s_tex.img = mlx_xpm_file_to_image(user->mlx, user->so_path, &width,
			&height);
	if (!user->s_tex.img)
		cleanup(user, ERROR, "Error\nFailed to load south texture\n");
	user->s_tex.data = mlx_get_data_addr(user->s_tex.img, &user->s_tex.bpp,
			&user->s_tex.line_len, &user->s_tex.endian);
	user->s_tex.width = width;
	user->s_tex.height = height;
	user->w_tex.img = mlx_xpm_file_to_image(user->mlx, user->we_path, &width,
			&height);
	if (!user->w_tex.img)
		cleanup(user, ERROR, "Error\nFailed to load west texture\n");
	user->w_tex.data = mlx_get_data_addr(user->w_tex.img, &user->w_tex.bpp,
			&user->w_tex.line_len, &user->w_tex.endian);
	user->w_tex.width = width;
	user->w_tex.height = height;
	user->e_tex.img = mlx_xpm_file_to_image(user->mlx, user->ea_path, &width,
			&height);
	if (!user->e_tex.img)
		cleanup(user, ERROR, "Error\nFailed to load east texture\n");
	user->e_tex.data = mlx_get_data_addr(user->e_tex.img, &user->e_tex.bpp,
			&user->e_tex.line_len, &user->e_tex.endian);
	user->e_tex.width = width;
	user->e_tex.height = height;
}

static unsigned int	extract_color(t_rgb color)
{
	return ((color.red << 16) | (color.green << 8) | color.blue);
}

static void	convert_color(t_user *user)
{
	user->ceiling_c = extract_color(user->ceiling);
	user->floor_c = extract_color(user->floor);
}
void	fill_spaces_with_walls(t_user *user)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (user->map[y])
	{
		x = 0;
		while (user->map[y][x])
		{
			if (user->map[y][x] == ' ')
				user->map[y][x] = '1';
			x++;
		}
		y++;
	}
}

int	game_loop(t_user *user)
{
	int mouse_zone;
	
	if (user->vars.key_w)
		move_forward(user);
	if (user->vars.key_s)
		move_backward(user);
	if (user->vars.key_a)
		move_left(user);
	if (user->vars.key_d)
		move_right(user);
	if (user->vars.key_arr_l)
		rotate_left(user);
	if (user->vars.key_arr_r)
		rotate_right(user);
	mouse_zone = SCREEN_WIDTH / 4;
	if (user->vars.mouse_pos > SCREEN_WIDTH / 2 + mouse_zone)
		rotate_right(user);
	if (user->vars.mouse_pos < SCREEN_WIDTH / 2 - mouse_zone)
		rotate_left(user);
	ft_bzero(user->image.img_data, SCREEN_WIDTH * SCREEN_HEIGHT * 4);
	draw_ray(user);
	mlx_put_image_to_window(user->mlx, user->mlx_win, user->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_user	user;

	if (argc != 2)
		return (ft_putendl_fd("Error\nInvalid number of arguments!", 2), 1);
	intialise_data(&user);
	validate_file_extension(argv[1]);
	parse_input(argv[1], &user);
	fill_spaces_with_walls(&user);
	convert_color(&user);
	open_window(&user);
	load_textures(&user);
	draw_ray(&user);
	mlx_put_image_to_window(user.mlx, user.mlx_win, user.img, 0, 0);
	set_up_hooks(&user);
	mlx_loop_hook(user.mlx, game_loop, &user);
	mlx_loop(user.mlx);
	cleanup(&user, SUCCESS, NULL);
	return (0);
}
