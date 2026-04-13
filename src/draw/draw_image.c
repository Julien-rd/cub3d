/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:44:11 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/13 15:36:32 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

static t_image	*get_texture(t_user *user, t_dda *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x >= 0)
			return (&user->tex.w);
		return (&user->tex.e);
	}
	else
	{
		if (ray->dir.y >= 0)
			return (&user->tex.n);
		return (&user->tex.s);
	}
}

static void	init_draw(t_user *user, t_dda *ray, t_draw *wall)
{
	double	wall_x;

	ft_bzero(wall, sizeof(t_draw));
	if (ray->perp_dist_wall == 0.0)
		ray->perp_dist_wall = 0.0001;
	wall->line_height = (int)(SCREEN_HEIGHT / ray->perp_dist_wall);
	if (wall->line_height <= 0)
		wall->line_height = 1;
	wall->start = -wall->line_height / 2 + SCREEN_HEIGHT / 2;
	if (wall->start < 0)
		wall->start = 0;
	wall->end = wall->line_height / 2 + SCREEN_HEIGHT / 2;
	if (wall->end >= SCREEN_HEIGHT)
		wall->end = SCREEN_HEIGHT - 1;
	wall->tex = get_texture(user, ray);
	if (ray->side == 0)
		wall_x = user->player.pos.y + ray->perp_dist_wall * ray->dir.y;
	else
		wall_x = user->player.pos.x + ray->perp_dist_wall * ray->dir.x;
	wall_x -= floor(wall_x);
	wall->tex_x = (int)(wall_x * wall->tex->width);
	if ((ray->side == 0 && ray->dir.x > 0)
		|| (ray->side == 1 && ray->dir.y < 0))
		wall->tex_x = wall->tex->width - wall->tex_x - 1;
}

static void	draw_texture(t_user *user, t_draw wall, int x)
{
	int		y;
	int		colour;
	double	tex_pos;
	int		tex_y;
	double	step;

	step = (double)wall.tex->height / wall.line_height;
	tex_pos = (wall.start - SCREEN_HEIGHT / 2 + wall.line_height / 2) * step;
	y = wall.start;
	while (y <= wall.end)
	{
		tex_y = (int)tex_pos;
		if (tex_y >= wall.tex->height)
			tex_y = wall.tex->height - 1;
		if (tex_y < 0)
			tex_y = 0;
		tex_pos += step;
		colour = *(int *)(wall.tex->data
				+ (tex_y * wall.tex->line + wall.tex_x * (wall.tex->bpp / 8)));
		ft_put_pixel(x, y, user, colour);
		y++;
	}
}

static void	draw_vertical(t_user *user, t_dda *ray, int x)
{
	int		y;
	t_draw	wall;

	y = 0;
	init_draw(user, ray, &wall);
	while (y < wall.start)
	{
		ft_put_pixel(x, y, user, user->ceiling.colour);
		y++;
	}
	draw_texture(user, wall, x);
	y = wall.end + 1;
	while (y < SCREEN_HEIGHT)
	{
		ft_put_pixel(x, y, user, user->floor.colour);
		y++;
	}
}

void	draw_image(t_user *user)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		draw_vertical(user, user->ray[x], x);
		x++;
	}
}
