/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:17:32 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/21 11:19:19 by vmanuyko         ###   ########.fr       */
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

static void	draw_player(t_user *user, t_camera *cam, unsigned int colour)
{
	int	start_x;
	int	start_y;
	int	draw_x;
	int	draw_y;

	start_x = (user->player.pos.x - cam->min.x) * PLAYER_TILE;
	start_y = (user->player.pos.y - cam->min.y) * PLAYER_TILE;
	draw_y = 0;
	while (draw_y < PLAYER_TILE)
	{
		draw_x = 0;
		while (draw_x < PLAYER_TILE)
		{
			ft_put_pixel(start_x + draw_x, start_y + draw_y, user, colour);
			draw_x++;
		}
		draw_y++;
	}
}

static void	init_camera(t_camera *cam, t_user *user)
{
	cam->min.x = user->player.pos.x - VIEW_LENGTH;
	cam->max.x = user->player.pos.x + VIEW_LENGTH;
	cam->min.y = user->player.pos.y - VIEW_LENGTH;
	cam->max.y = user->player.pos.y + VIEW_LENGTH;
	cam->min.x = fmax(0, cam->min.x);
	cam->min.y = fmax(0, cam->min.y);
	cam->max.x = fmin(MINI_SIZE - 1, cam->max.x);
	cam->max.y = fmin(MINI_SIZE - 1, cam->max.y);
}

void	draw_minimap(t_user *user)
{
	int			x;
	int			y;
	t_camera	cam;

	ft_bzero(user->tex.img.data, SCREEN_HEIGHT * user->tex.img.line);
	init_camera(&cam, user);
	y = (int)cam.min.y;
	while (y < (int)cam.max.y)
	{
		x = (int)cam.min.x;
		while (x < (int)cam.max.x)
		{
			if (user->map[y][x] == '1')
				draw_square(user, x - cam.min.x, y - cam.min.y, GREEN);
			x++;
		}
		y++;
	}
	draw_player(user, &cam, RED);
}
