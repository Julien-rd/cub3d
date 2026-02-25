/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:35:54 by jromann           #+#    #+#             */
/*   Updated: 2026/02/02 18:52:30 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	is_wall_at(t_user *user, double x, double y)
{
	int	map_x;
	int	map_y;
	int	map_height;

	map_x = (int)x;
	map_y = (int)y;
	map_height = 0;
	while (user->map[map_height])
		map_height++;
	if (map_y < 0 || map_y >= map_height)
		return (true);
	if (map_x < 0 || map_x >= (int)ft_strlen(user->map[map_y]))
		return (true);
	return (user->map[map_y][map_x] == '1');
}

bool	check_collision(t_user *user, double x, double y)
{
	double	buffer;

	buffer = 0.2;
	if (is_wall_at(user, x - buffer, y - buffer))
		return (true);
	if (is_wall_at(user, x + buffer, y - buffer))
		return (true);
	if (is_wall_at(user, x - buffer, y + buffer))
		return (true);
	if (is_wall_at(user, x + buffer, y + buffer))
		return (true);
	return (false);
}
