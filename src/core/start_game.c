/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:26:56 by jromann           #+#    #+#             */
/*   Updated: 2026/03/17 15:15:48 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	game_loop(t_user *user)
{
	int	mouse_zone;

	move_player(user);
	mouse_zone = SCREEN_WIDTH / 4;
	if (user->key.mouse_pos > SCREEN_WIDTH / 2 + mouse_zone)
		rotate_right(user);
	if (user->key.mouse_pos < SCREEN_WIDTH / 2 - mouse_zone)
		rotate_left(user);
	draw_image(user);
	mlx_put_image_to_window(user->mlx, user->mlx_win, user->tex.img.img, 0, 0);
	return (0);
}

void	start_game(t_user *user)
{
	set_up_hooks(user);
	mlx_loop_hook(user->mlx, game_loop, user);
	mlx_loop(user->mlx);
}
