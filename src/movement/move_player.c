/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:35:18 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/12 18:16:44 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player(t_user *user)
{
	double	new_x;
	double	new_y;
	int	dir_x;
	int	dir_y;

	dir_x = user->key.s - user->key.w;
	dir_y = user->key.a - user->key.d;
	new_x = user->player_pos.x + dir_x * MOVE_S;
	new_y = user->player_pos.y + dir_y * MOVE_S;
	if (!check_collision(user, new_x, new_y))
	{
		user->player_pos.x = new_x;
		user->player_pos.y = new_y;
	}
	if (user->key.arr_l)
		rotate_left(user);
	if (user->key.arr_r)
		rotate_right(user);
}
