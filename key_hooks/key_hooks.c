/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:54:43 by jromann           #+#    #+#             */
/*   Updated: 2026/03/11 12:35:43 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	close_hook(t_user *user)
{
	cleanup(user, SUCCESS, NULL);
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

static int	key_release_hook(int keycode, t_user *user)
{
	if (keycode == 119)
		user->vars.key_w = false;
	if (keycode == 115)
		user->vars.key_s = false;
	if (keycode == 97)
		user->vars.key_a = false;
	if (keycode == 100)
		user->vars.key_d = false;
	if (keycode == 65361)
		user->vars.key_arr_l = false;
	if (keycode == 65363)
		user->vars.key_arr_r = false;
	return (0);
}

static int	key_press_hook(int keycode, t_user *user)
{
	if (keycode == 65307)
		cleanup(user, SUCCESS, NULL);
	if (keycode == 119)
		user->vars.key_w = true;
	if (keycode == 115)
		user->vars.key_s = true;
	if (keycode == 97)
		user->vars.key_a = true;
	if (keycode == 100)
		user->vars.key_d = true;
	if (keycode == 65361)
		user->vars.key_arr_l = true;
	if (keycode == 65363)
		user->vars.key_arr_r = true;
	return (0);
}

void	set_up_hooks(t_user *user)
{
	mlx_hook(user->mlx_win, 6, 1L << 6, mouse_hook, user);
	mlx_hook(user->mlx_win, 8, 1L << 5, mouse_left_win_hook, user);
	mlx_hook(user->mlx_win, 2, 1L << 0, key_press_hook, user);
	mlx_hook(user->mlx_win, 3, 1L << 1, key_release_hook, user);
	mlx_hook(user->mlx_win, 17, 0, close_hook, user);
}
