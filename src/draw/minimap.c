/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:17:32 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/24 14:39:22 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

static void	draw_square(t_user *user, int x, int y, unsigned int colour)
{
	int	start_x;
	int	start_y;
	int	draw_x;
	int	draw_y;

	start_x = MINI_OFFSET + x * MINI_TILE;
	start_y = MINI_OFFSET + y * MINI_TILE;
	draw_y = 0;
	if (start_x < 0 || start_y < 0
		|| start_x > MINI_SIZE || start_y > MINI_SIZE)
		return ;
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

static void	draw_player(t_user *user, t_vector pos, t_camera *cam)
{
	int	start_x;
	int	start_y;
	int	draw_x;
	int	draw_y;

	start_x = MINI_OFFSET + (pos.x - cam->min.x) * MINI_TILE - PLAYER_TILE / 2;
	start_y = MINI_OFFSET + (pos.y - cam->min.y) * MINI_TILE - PLAYER_TILE / 2;
	draw_y = 0;
	while (draw_y < PLAYER_TILE)
	{
		draw_x = 0;
		while (draw_x < PLAYER_TILE)
		{
			ft_put_pixel(start_x + draw_x, start_y + draw_y, user, RED);
			draw_x++;
		}
		draw_y++;
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
/*
 * TO DO: add dda + draw_ray in a loop for each ray casted,
 * so that the player on the minimap has a FOV representation*.
*/
void	draw_minimap(t_user *user)
{
	int			x;
	int			y;
	t_camera	cam;
	char		tile;

	init_camera(&cam, user);
	y = (int)cam.min.y;
	while (y < (int)cam.max.y)
	{
		x = (int)cam.min.x;
		while (x < (int)cam.max.x)
		{
			tile = get_tile(x, y, user->map);
			if (tile == '1' || tile == ' ')
				draw_square(user, x -(int)cam.min.x, y -(int)cam.min.y, BLUE);
			if (tile == '0' || tile == user->start_dir)
				draw_square(user, x -(int)cam.min.x, y -(int)cam.min.y, WHITE);
			x++;
		}
		y++;
	}
	draw_player(user, user->player.pos, &cam);
	draw_ray(user, &cam);
}
