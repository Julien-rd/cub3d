/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:22:16 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/14 13:34:19 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

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
static void	init_line(t_line *l, t_player p)
{
	l->start.x = MINI_OFFSET + MINI_SIZE / 2;
	l->start.y = MINI_OFFSET + MINI_SIZE / 2;
	l->end.x = l->start.x + (p.dir.x * 2) * MINI_TILE;
	l->end.y = l->start.y + (p.dir.y * 2) * MINI_TILE;
	if (l->end.x > MINI_SIZE)
		l->end.x = MINI_SIZE;
	if (l->end.y > MINI_SIZE)
		l->end.y = MINI_SIZE;
	l->step.x = (l->end.x > l->start.x) - (l->end.x < l->start.x);
	l->step.y = (l->end.y > l->start.y) - (l->end.y < l->start.y);
	l->dist.x = abs(l->end.x - l->start.x);
	l->dist.y = abs(l->end.y - l->start.y);
	if (l->dist.x > l->dist.y)
	{
		l->a = 2 * l->dist.y;
		l->b = l->a - 2 * l->dist.x;
		l->p = l->a - l->dist.x;
	}
	else
	{
		l->a = 2 * l->dist.x;
		l->b = l->a - 2 * l->dist.y;
		l->p = l->a - l->dist.y;
	}
}

static void	draw_line(t_user *user, t_line *line, t_coord *pos, int axis)
{
	if (pos->x >= MINI_OFFSET && pos->x <= MINI_OFFSET + MINI_SIZE
		&& pos->y >= MINI_OFFSET && pos->y <= MINI_OFFSET + MINI_SIZE)
		ft_put_pixel(pos->x, pos->y, user, GREEN);
	if (axis == X_AXIS)
		pos->x += line->step.x;
	else if (axis == Y_AXIS)
		pos->y += line->step.y;
	if (line->p >= 0)
	{
		if (axis == X_AXIS)
			pos->y += line->step.y;
		else if (axis == Y_AXIS)
			pos->x += line->step.x;
		line->p += line->b;
	}
	else
		line->p += line->a;
}

/* First prototype of draw_ray for minimap, will draw a ray form
 * player position in direction, where he looks, later can be used,
 * but end shall be modified to use dist to a wall, where ray hits it.
*/
void	draw_ray(t_user *user)
{
	t_line	line;
	t_coord	pos;

	init_line(&line, user->player);
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
