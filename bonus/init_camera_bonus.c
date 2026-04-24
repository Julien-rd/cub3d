/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:30:19 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/14 14:30:21 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

void	init_camera(t_camera *cam, t_user *user)
{
	int	tiles;

	tiles = (MINI_SIZE / MINI_TILE);
	cam->min.x = (int)user->player.pos.x - tiles / 2;
	cam->max.x = cam->min.x + tiles;
	cam->min.y = (int)user->player.pos.y - tiles / 2;
	cam->max.y = cam->min.y + tiles;
}
