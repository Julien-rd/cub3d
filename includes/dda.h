/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:20:01 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/19 17:44:43 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "cub3d.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_dda
{
	double			camera_x;
	t_vector		dir;
	t_vector		delta_dist;
	t_vector		side_dist;
	t_coord			map;
	t_coord			step;
}	t_dda;

void	init_ray(t_user *user, t_dda *ray, int x);

#endif