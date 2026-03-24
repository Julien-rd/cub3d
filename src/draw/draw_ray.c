/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:02:21 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/24 14:39:07 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

# define DIR_LENGTH 2
/*
 * Initialises line struct with following variables:
 * We have start coordinate(the player coordinate) and
 * the end coordinate(start_coord -->end point of line).
 * Step(x/y) indicates the direction of where we will draw the line.
 * Line_dist(x/y) is used for defining, whether the line is more 
 * vertical or horisontal by calculating how much we will step in (X/Y)-axis.
 * A, B, P are used for the Bresenham algorithm calculations and
 * are set according to in which direction we will "step".
*/
static void	init_line(t_player p, t_camera *cam, t_line *l)
{
	l->start.x = MINI_OFFSET + ((p.pos.x - cam->min.x) * MINI_TILE);
	l->start.y = MINI_OFFSET + ((p.pos.y - cam->min.y) * MINI_TILE);
	l->end.x = l->start.x + (p.dir.x * DIR_LENGTH) * MINI_TILE;
	l->end.y = l->start.y + (p.dir.y * DIR_LENGTH) * MINI_TILE;
	l->step.x = (l->end.x > l->start.x) - (l->end.x < l->start.x);
	l->step.y = (l->end.y > l->start.y) - (l->end.y < l->start.y);
	l->dist.x = abs(l->end.x - l->start.x);
	l->dist.y = abs(l->end.y - l->start.y);
	if (l->dist.x > l->dist.y)
	{
		l->A = 2 * l->dist.y;
		l->B = l->A - 2 * l->dist.x;
		l->P = l->A - l->dist.x;
	}
	else
	{
		l->A = 2 * l->dist.x;
		l->B = l->A - 2 * l->dist.y;
		l->P = l->A - l->dist.y;
	}
}

static void	draw_line(t_user *user, t_line *line, t_coord *pos, int axis)
{
	ft_put_pixel(pos->x, pos->y, user, GREEN);
	if (axis == X_AXIS)
		pos->x += line->step.x;
	else if (axis == Y_AXIS)
		pos->y += line->step.y;
	if (line->P >= 0)
	{
		if (axis == X_AXIS)
			pos->y += line->step.y;
		else if (axis == Y_AXIS)
			pos->x += line->step.x;
		line->P += line->B;
	}
	else
		line->P += line->A;
}

/* First prototype of draw_ray for minimap, will draw a ray form
 * player position in direction, where he looks, later can be used,
 * but end shall be modified to use dist to a wall, where ray hits it.
*/
void	draw_ray(t_user *user, t_camera *cam)
{
	t_line	line;
	t_coord	pos;

	init_line(user->player, cam, &line);
	pos.x = line.start.x;
	pos.y = line.start.y;
	if (line.dist.x > line.dist.y)
	{
		while (pos.x != line.end.x)
			draw_line(user, &line, &pos, X_AXIS);
	}
	else
	{
		while (pos.y != line.end.y)
			draw_line(user, &line, &pos, Y_AXIS);
	}
}
