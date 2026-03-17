/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:20:01 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/17 16:48:59 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

#include "cub3d.h"

typedef struct s_dda
{
	double			camera_x;
	t_coord			dir;
	t_coord			delta_dist;
	t_coord			side_dist;
	int				step_x;
	int				step_y;
	int				side;
	double			perp_wall_dist;
}	t_dda;

#endif