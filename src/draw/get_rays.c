/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:03:26 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/13 15:04:26 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

static void	hit_wall(t_user *user, t_dda *ray)
{
	int	map_height;

	map_height = 0;
	while (user->map[map_height])
		map_height++;
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (ray->map.y < 0 || ray->map.y >= map_height || ray->map.x < 0
			|| ray->map.x >= (int)ft_strlen(user->map[ray->map.y]))
			ray->hit = 1;
		if (user->map[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
}

static void	perp_dist_to_wall(t_dda *ray)
{
	if (ray->side == 0)
		ray->perp_dist_wall = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_dist_wall = ray->side_dist.y - ray->delta_dist.y;
}

void	get_rays(t_user *user)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
		ft_bzero(user->ray[x++], sizeof(t_dda));
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray(user, user->ray[x], x);
		hit_wall(user, user->ray[x]);
		perp_dist_to_wall(user->ray[x]);
		x++;
	}
}
