/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:17:32 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/19 20:24:17 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

static void	ft_put_pixel(int x, int y, t_user *user, unsigned int colour)
{
	int	pos;

	pos = y * user->tex.img.line + x * (user->tex.img.bpp / 8);
	*(unsigned int *)(user->tex.img.data + pos) = colour;
}

static void	draw_square(t_user *user, int x, int y, unsigned int colour)
{
	int	start_x;
	int	start_y;
	int	draw_x;
	int	draw_y;

	start_x = x * MINI_TILE;
	start_y = y * MINI_TILE;
	draw_y = 0;
	while (draw_y < MINI_TILE)
	{
		draw_x = 0;
		while (draw_x < MINI_TILE)
		{
			ft_put_pixel(start_x + draw_x, start_y + draw_y, user, colour);
			draw_x++;
		}
		draw_y++;
	}
}

void	draw_minimap(t_user *user)
{
	int	x;
	int	y;

	y = 0;
	while (user->map[y])
	{
		x = 0;
		while (user->map[y][x])
		{
			if (user->map[y][x] == '1')
				draw_square(user, x, y, GREEN);
			if (user->map[y][x] == 'P')
				draw_square(user, x, y, RED);
			x++;
		}
		y++;
	}
}
