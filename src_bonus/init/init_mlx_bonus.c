/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:19:54 by jromann           #+#    #+#             */
/*   Updated: 2026/03/17 11:37:06 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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

static void	load_textures_walls(t_user *user)
{
	user->tex.n.img = mlx_xpm_file_to_image(user->mlx, user->path.no,
			&user->tex.n.width, &user->tex.n.height);
	if (!user->tex.n.img)
		exit_game(user, ERROR, "Error\nFailed to load north texture\n");
	user->tex.n.data = mlx_get_data_addr(user->tex.n.img, &user->tex.n.bpp,
			&user->tex.n.line, &user->tex.n.endian);
	user->tex.s.img = mlx_xpm_file_to_image(user->mlx, user->path.so,
			&user->tex.s.width, &user->tex.s.height);
	if (!user->tex.s.img)
		exit_game(user, ERROR, "Error\nFailed to load south texture\n");
	user->tex.s.data = mlx_get_data_addr(user->tex.s.img, &user->tex.s.bpp,
			&user->tex.s.line, &user->tex.s.endian);
	user->tex.w.img = mlx_xpm_file_to_image(user->mlx, user->path.we,
			&user->tex.w.width, &user->tex.w.height);
	if (!user->tex.w.img)
		exit_game(user, ERROR, "Error\nFailed to load west texture\n");
	user->tex.w.data = mlx_get_data_addr(user->tex.w.img, &user->tex.w.bpp,
			&user->tex.w.line, &user->tex.w.endian);
	user->tex.e.img = mlx_xpm_file_to_image(user->mlx, user->path.ea,
			&user->tex.e.width, &user->tex.e.height);
	if (!user->tex.e.img)
		exit_game(user, ERROR, "Error\nFailed to load east texture\n");
	user->tex.e.data = mlx_get_data_addr(user->tex.e.img, &user->tex.e.bpp,
			&user->tex.e.line, &user->tex.e.endian);
}

static void	load_textures_door(t_user *user)
{
	if(user->door_present == false)
		return ;
	user->tex.d.img = mlx_xpm_file_to_image(user->mlx, user->path.dr,
			&user->tex.d.width, &user->tex.d.height);
	if (!user->tex.d.img)
		exit_game(user, ERROR, "Error\nFailed to load door texture\n");
	user->tex.d.data = mlx_get_data_addr(user->tex.d.img, &user->tex.d.bpp,
			&user->tex.d.line, &user->tex.d.endian); //can this fail?
}

void	init_graphics(t_user *user)
{
	open_window(user);
	load_textures_walls(user);
	load_textures_door(user);
}
