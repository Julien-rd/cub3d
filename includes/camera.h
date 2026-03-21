/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:15:40 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/20 13:55:58 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "dda.h"

# define VIEW_LENGTH 10

typedef struct	s_camera
{
	t_vector	min;
	t_vector	max;
}	t_camera;

#endif