/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:58:33 by jromann           #+#    #+#             */
/*   Updated: 2026/02/02 18:52:33 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_user *user, bool *flag)
{
	double	new_x;
	double	new_y;

	new_x = user->player_pos.x + user->dir_vec.x * MOVE_S;
	new_y = user->player_pos.y + user->dir_vec.y * MOVE_S;
	if (!check_collision(user, new_x, new_y))
	{
		user->player_pos.x = new_x;
		user->player_pos.y = new_y;
		*flag = true;
	}
}

void	move_backward(t_user *user, bool *flag)
{
	double	new_x;
	double	new_y;

	new_x = user->player_pos.x - user->dir_vec.x * MOVE_S;
	new_y = user->player_pos.y - user->dir_vec.y * MOVE_S;
	if (!check_collision(user, new_x, new_y))
	{
		user->player_pos.x = new_x;
		user->player_pos.y = new_y;
		*flag = true;
	}
}

void	move_left(t_user *user, bool *flag)
{
	double	new_x;
	double	new_y;

	new_x = user->player_pos.x - user->plane_vec.x * MOVE_S;
	new_y = user->player_pos.y - user->plane_vec.y * MOVE_S;
	if (!check_collision(user, new_x, new_y))
	{
		user->player_pos.x = new_x;
		user->player_pos.y = new_y;
		*flag = true;
	}
}

void	move_right(t_user *user, bool *flag)
{
	double	new_x;
	double	new_y;

	new_x = user->player_pos.x + user->plane_vec.x * MOVE_S;
	new_y = user->player_pos.y + user->plane_vec.y * MOVE_S;
	if (!check_collision(user, new_x, new_y))
	{
		user->player_pos.x = new_x;
		user->player_pos.y = new_y;
		*flag = true;
	}
}
