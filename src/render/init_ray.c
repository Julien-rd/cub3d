/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:43:04 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/19 17:53:14 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

static void	init_side_dist(t_dda *ray, int pos_x, int pos_y)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (pos_x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1 - pos_x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (pos_y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1 - pos_y) * ray->delta_dist.y;
	}
}

void	init_ray(t_user *user, t_dda *ray, int x)
{
	ray->map.x = (int)user->player.pos.x;
	ray->map.y = (int)user->player.pos.y;
	ray->camera_x = 2 * x / SCREEN_WIDTH -1;
	ray->dir.x = user->player.dir.x + user->plane.x * ray->camera_x;
	ray->dir.y = user->player.dir.y + user->plane.y * ray->camera_x;
	if (ray->dir.x == 0)
		ray->delta_dist.x = INFINITY;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = INFINITY;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
	init_side_dist(ray, user->player.pos.x, user->player.pos.y);
}
