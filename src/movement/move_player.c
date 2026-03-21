/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:35:18 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/20 14:23:08 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player(t_user *user)
{
	double	new_x;
	double	new_y;
	double	move_forward;
	double	move_right;

	move_forward = user->key.w - user->key.s;
	move_right = user->key.d - user->key.a;
	new_x = user->player.pos.x + (move_forward * user->player.dir.x * MOVE_S);
	new_x += (move_right * user->plane.x * MOVE_S);
	new_y = user->player.pos.y + (move_forward * user->player.dir.y * MOVE_S);
	new_y += (move_right * user->plane.y * MOVE_S);
	if (!check_collision(user, new_x, user->player.pos.y))
		user->player.pos.x = new_x;
	if (!check_collision(user, user->player.pos.x, new_y))
		user->player.pos.y = new_y;
	if (user->key.arr_l)
		rotate_left(user);
	if (user->key.arr_r)
		rotate_right(user);
}
