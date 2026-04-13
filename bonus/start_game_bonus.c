/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:15:32 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/13 18:15:35 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

int	game_loop(t_user *user)
{
	int	mouse_zone;

	move_player(user);
	mouse_zone = SCREEN_WIDTH / 4;
	if (user->key.mouse_pos > SCREEN_WIDTH / 2 + mouse_zone)
		rotate_right(user);
	if (user->key.mouse_pos < SCREEN_WIDTH / 2 - mouse_zone)
		rotate_left(user);
	ft_bzero(user->tex.img.data, SCREEN_HEIGHT * user->tex.img.line);
	get_rays(user);
	draw_image(user);
	draw_minimap(user);
	mlx_put_image_to_window(user->mlx, user->mlx_win, user->tex.img.img, 0, 0);
	return (0);
}

void	start_game(t_user *user)
{
	set_up_hooks(user);
	mlx_loop_hook(user->mlx, game_loop, user);
	mlx_loop(user->mlx);
}
