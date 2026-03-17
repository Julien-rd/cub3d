/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:54:43 by jromann           #+#    #+#             */
/*   Updated: 2026/03/12 16:42:21 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_hook(t_user *user)
{
	exit_game(user, SUCCESS, NULL);
	return (0);
}

int	mouse_hook(int x, int y, t_user *user)
{
	(void)y;
	user->key.mouse_pos = x;
	return (0);
}

int	mouse_left_win_hook(t_user *user)
{
	user->key.mouse_pos = SCREEN_WIDTH / 2;
	return (0);
}

int	key_release_hook(int keycode, t_user *user)
{
	if (keycode == KEY_W)
		user->key.w = false;
	if (keycode == KEY_S)
		user->key.s = false;
	if (keycode == KEY_A)
		user->key.a = false;
	if (keycode == KEY_D)
		user->key.d = false;
	if (keycode == KEY_ARR_L)
		user->key.arr_l = false;
	if (keycode == KEY_ARR_R)
		user->key.arr_r = false;
	return (0);
}

int	key_press_hook(int keycode, t_user *user)
{
	if (keycode == KEY_ESC)
		exit_game(user, SUCCESS, NULL);
	if (keycode == KEY_W)
		user->key.w = true;
	if (keycode == KEY_S)
		user->key.s = true;
	if (keycode == KEY_A)
		user->key.a = true;
	if (keycode == KEY_D)
		user->key.d = true;
	if (keycode == KEY_ARR_L)
		user->key.arr_l = true;
	if (keycode == KEY_ARR_R)
		user->key.arr_r = true;
	return (0);
}
