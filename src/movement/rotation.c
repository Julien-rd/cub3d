/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:13:14 by jromann           #+#    #+#             */
/*   Updated: 2026/03/27 16:07:02 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_right(t_user *user)
{
	double	dir_x;
	double	plane_x;

	dir_x = user->player.dir.x;
	plane_x = user->plane.x;
	user->player.dir.x = dir_x * cos(ROT_S) - user->player.dir.y
		* sin(ROT_S);
	user->player.dir.y = dir_x * sin(ROT_S) + user->player.dir.y * cos(ROT_S);
	user->plane.x = plane_x * cos(ROT_S) - user->plane.y
		* sin(ROT_S);
	user->plane.y = plane_x * sin(ROT_S) + user->plane.y * cos(ROT_S);
}

void	rotate_left(t_user *user)
{
	double	dir_x;
	double	plane_x;

	dir_x = user->player.dir.x;
	plane_x = user->plane.x;
	user->player.dir.x = user->player.dir.x * cos(-ROT_S) - user->player.dir.y
		* sin(-ROT_S);
	user->player.dir.y = dir_x * sin(-ROT_S) + user->player.dir.y * cos(-ROT_S);
	user->plane.x = user->plane.x * cos(-ROT_S) - user->plane.y
		* sin(-ROT_S);
	user->plane.y = plane_x * sin(-ROT_S) + user->plane.y * cos(-ROT_S);
}
