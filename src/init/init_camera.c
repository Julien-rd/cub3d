/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:50:22 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/21 13:56:39 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

void	init_camera(t_camera *cam, t_user *user)
{
	int	tiles;

	tiles = (MINI_SIZE / MINI_TILE);
	cam->min.x = user->player.pos.x - tiles / 2;
	cam->max.x = (int)cam->min.x + tiles;
	cam->min.y = user->player.pos.y - tiles / 2;
	cam->max.y = (int)cam->min.y + tiles;
}
