/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:21:37 by jromann           #+#    #+#             */
/*   Updated: 2026/03/12 09:38:43 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_hook(t_user *user)
{
	exit_game(user, SUCCESS, NULL);
	return (0);
}

int mouse_hook(int x, int y, t_user *user)
{
	(void)y;
	user->vars.mouse_pos = x;
    return (0);
}

int mouse_left_win_hook(t_user *user)
{
	user->vars.mouse_pos = SCREEN_WIDTH / 2;
	return (0);
}

int	key_release_hook(int keycode, t_user *user)
{
	if (keycode == KEY_W)
		user->vars.key_w = false;
	if (keycode == KEY_S)
		user->vars.key_s = false;
	if (keycode == KEY_A)
		user->vars.key_a = false;
	if (keycode == KEY_D)
		user->vars.key_d = false;
	if (keycode == KEY_ARR_L)
		user->vars.key_arr_l = false;
	if (keycode == KEY_ARR_R)
		user->vars.key_arr_r = false;
	return (0);
}

int	key_press_hook(int keycode, t_user *user)
{
	if (keycode == KEY_ESC)
		exit_game(user, SUCCESS, NULL);
	if (keycode == KEY_W)
		user->vars.key_w = true;
	if (keycode == KEY_S)
		user->vars.key_s = true;
	if (keycode == KEY_A)
		user->vars.key_a = true;
	if (keycode == KEY_D)
		user->vars.key_d = true;
	if (keycode == KEY_ARR_L)
		user->vars.key_arr_l = true;
	if (keycode == KEY_ARR_R)
		user->vars.key_arr_r = true;
	return (0);
}