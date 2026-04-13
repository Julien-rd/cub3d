/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:22:27 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/13 18:22:30 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

static void	draw_square(t_user *user, int x, int y, unsigned int colour)
{
	t_coord	start;
	t_coord	draw;

	start.x = MINI_OFFSET + x * MINI_TILE;
	start.y = MINI_OFFSET + y * MINI_TILE;
	draw.y = 0;
	if (start.x < 0 || start.y < 0
		|| start.x > MINI_SIZE || start.y > MINI_SIZE)
		return ;
	while (draw.y < MINI_TILE)
	{
		draw.x = 0;
		while (draw.x < MINI_TILE)
		{
			ft_put_pixel(start.x + draw.x, start.y + draw.y, user, colour);
			draw.x++;
		}
		draw.y++;
	}
}

static void	draw_player(t_user *user)
{
	t_coord	start;
	t_coord	draw;

	start.x = MINI_OFFSET + MINI_SIZE / 2 - PLAYER_TILE / 2;
	start.y = MINI_OFFSET + MINI_SIZE / 2 - PLAYER_TILE / 2;
	draw.y = 0;
	while (draw.y < PLAYER_TILE)
	{
		draw.x = 0;
		while (draw.x < PLAYER_TILE)
		{
			ft_put_pixel(start.x + draw.x, start.y + draw.y, user, RED);
			draw.x++;
		}
		draw.y++;
	}
}

static char	get_tile(int x, int y, char **map)
{
	int	map_height;

	map_height = 0;
	while (map[map_height])
		map_height++;
	if (y < 0 || y >= map_height)
		return (' ');
	if (x < 0 || x >= (int)ft_strlen(map[y]))
		return (' ');
	return (map[y][x]);
}

void	draw_minimap(t_user *user)
{
	int			x;
	int			y;
	t_camera	cam;
	char		tile;

	init_camera(&cam, user);
	y = cam.min.y;
	while (y < cam.max.y)
	{
		x = cam.min.x;
		while (x < cam.max.x)
		{
			tile = get_tile(x, y, user->map);
			if (tile == '1' || tile == ' ')
				draw_square(user, x - cam.min.x, y - cam.min.y, BLUE);
			if (tile == '0' || tile == user->start_dir)
				draw_square(user, x - cam.min.x, y - cam.min.y, WHITE);
			x++;
		}
		y++;
	}
	draw_player(user);
	draw_ray(user);
}
