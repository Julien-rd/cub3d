/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:54:43 by jromann           #+#    #+#             */
/*   Updated: 2026/03/12 09:22:03 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_up_hooks(t_user *user)
{
	mlx_hook(user->mlx_win, 6, 1L << 6, mouse_hook, user);
	mlx_hook(user->mlx_win, 8, 1L << 5, mouse_left_win_hook, user);
	mlx_hook(user->mlx_win, 2, 1L << 0, key_press_hook, user);
	mlx_hook(user->mlx_win, 3, 1L << 1, key_release_hook, user);
	mlx_hook(user->mlx_win, 17, 0, close_hook, user);
}
