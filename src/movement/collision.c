/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:35:54 by jromann           #+#    #+#             */
/*   Updated: 2026/03/16 14:15:21 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	is_wall_at(t_user *user, double x, double y)
{
	return (user->map[(int)y][(int)x] == '1');
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
