/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:19:54 by jromann           #+#    #+#             */
/*   Updated: 2026/03/13 12:35:48 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	open_window(t_user *user)
{
	user->mlx = mlx_init();
	if (!user->mlx)
		exit_game(user, ERROR, "Error\nmlx_init failed");
	user->mlx_win = mlx_new_window(user->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cub3D");
	if (!user->mlx_win)
		exit_game(user, ERROR, "Error\nmlx_new_window failed");
	user->tex.img.img= mlx_new_image(user->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!user->tex.img.img)
		exit_game(user, ERROR, "Error\nmlx_new_img failed");
	user->tex.img.data = mlx_get_data_addr(user->tex.img.img, &user->tex.img.bpp,
			&user->tex.img.line, &user->tex.img.endian);
	if (!user->tex.img.data)
		exit_game(user, ERROR, "Error\nmlx_get_data_addr nofailed");
}

static void	load_textures(t_user *user)
{
	user->tex.n.img = mlx_xpm_file_to_image(user->mlx, user->path.no,
			&user->tex.n.width, &user->tex.n.height);
	if (!user->tex.n.img)
		exit_game(user, ERROR, "Error\nFailed to load north texture");
	user->tex.n.data = mlx_get_data_addr(user->tex.n.img, &user->tex.n.bpp,
			&user->tex.n.line, &user->tex.n.endian);
	user->tex.s.img = mlx_xpm_file_to_image(user->mlx, user->path.so,
			&user->tex.s.width, &user->tex.s.height);
	if (!user->tex.s.img)
		exit_game(user, ERROR, "Error\nFailed to load south texture");
	user->tex.s.data = mlx_get_data_addr(user->tex.s.img, &user->tex.s.bpp,
			&user->tex.s.line, &user->tex.s.endian);
	user->tex.w.img = mlx_xpm_file_to_image(user->mlx, user->path.we,
			&user->tex.w.width, &user->tex.w.height);
	if (!user->tex.w.img)
		exit_game(user, ERROR, "Error\nFailed to load west texture");
	user->tex.w.data = mlx_get_data_addr(user->tex.w.img, &user->tex.w.bpp,
			&user->tex.w.line, &user->tex.w.endian);
	user->tex.e.img = mlx_xpm_file_to_image(user->mlx, user->path.ea,
			&user->tex.e.width, &user->tex.e.height);
	if (!user->tex.e.img)
		exit_game(user, ERROR, "Error\nFailed to load east texture");
	user->tex.e.data = mlx_get_data_addr(user->tex.e.img, &user->tex.e.bpp,
			&user->tex.e.line, &user->tex.e.endian);
}

void	init_graphics(t_user *user)
{
	open_window(user);
	load_textures(user);
}
