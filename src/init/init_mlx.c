/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:19:54 by jromann           #+#    #+#             */
/*   Updated: 2026/03/12 09:38:43 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	open_window(t_user *user)
{
	user->mlx = mlx_init();
	if (!user->mlx)
		exit_game(user, ERROR, "Error\nmlx_init failed\n");
	user->mlx_win = mlx_new_window(user->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cub3D");
	if (!user->mlx_win)
		exit_game(user, ERROR, "Error\nmlx_new_window failed\n");
	user->img = mlx_new_image(user->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!user->img)
		exit_game(user, ERROR, "Error\nmlx_new_img failed\n");
	user->image.img_data = mlx_get_data_addr(user->img, &user->image.bpp,
			&user->image.size_line, &user->image.endian);
	if (!user->image.img_data)
		exit_game(user, ERROR, "Error\nmlx_get_data_addr nofailed\n");
}

static void	load_textures(t_user *user)
{
	int	width;
	int	height;

	user->n_tex.img = mlx_xpm_file_to_image(user->mlx, user->no_path, &width,
			&height);
	if (!user->n_tex.img)
		exit_game(user, ERROR, "Error\nFailed to load north texture\n");
	user->n_tex.data = mlx_get_data_addr(user->n_tex.img, &user->n_tex.bpp,
			&user->n_tex.line_len, &user->n_tex.endian);
	user->n_tex.width = width;
	user->n_tex.height = height;
	user->s_tex.img = mlx_xpm_file_to_image(user->mlx, user->so_path, &width,
			&height);
	if (!user->s_tex.img)
		exit_game(user, ERROR, "Error\nFailed to load south texture\n");
	user->s_tex.data = mlx_get_data_addr(user->s_tex.img, &user->s_tex.bpp,
			&user->s_tex.line_len, &user->s_tex.endian);
	user->s_tex.width = width;
	user->s_tex.height = height;
	user->w_tex.img = mlx_xpm_file_to_image(user->mlx, user->we_path, &width,
			&height);
	if (!user->w_tex.img)
		exit_game(user, ERROR, "Error\nFailed to load west texture\n");
	user->w_tex.data = mlx_get_data_addr(user->w_tex.img, &user->w_tex.bpp,
			&user->w_tex.line_len, &user->w_tex.endian);
	user->w_tex.width = width;
	user->w_tex.height = height;
	user->e_tex.img = mlx_xpm_file_to_image(user->mlx, user->ea_path, &width,
			&height);
	if (!user->e_tex.img)
		exit_game(user, ERROR, "Error\nFailed to load east texture\n");
	user->e_tex.data = mlx_get_data_addr(user->e_tex.img, &user->e_tex.bpp,
			&user->e_tex.line_len, &user->e_tex.endian);
	user->e_tex.width = width;
	user->e_tex.height = height;
}

void init_graphics(t_user *user)
{
    open_window(user);
    load_textures(user);
}
