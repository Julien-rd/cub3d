/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:20:01 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/14 14:29:21 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "cub3d.h"

# define MINI_TILE 8
# define PLAYER_TILE 4
# define MINI_SIZE 184
# define MINI_OFFSET 20

# define RED 0xff0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF

# define X_AXIS 1
# define Y_AXIS 0

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_dda
{
	double		camera_x;
	t_vector	dir;
	t_vector	delta_dist;
	t_vector	side_dist;
	t_coord		map;
	t_coord		step;
	int			hit;
	int			side;
	double		perp_dist_wall;
}	t_dda;

typedef struct s_camera
{
	t_coord	min;
	t_coord	max;
}	t_camera;

typedef struct s_line
{
	int			a;
	int			b;
	int			p;
	t_coord		start;
	t_coord		end;
	t_coord		step;
	t_coord		dist;
}	t_line;

typedef struct s_draw
{
	int		start;
	int		end;
	t_image	*tex;
	int		tex_x;
	int		line_height;
}	t_draw;

void	init_ray(t_user *user, t_dda *ray, int x);
void	init_camera(t_camera *cam, t_user *user);
void	ft_put_pixel(int x, int y, t_user *user, unsigned int colour);
void	draw_ray(t_user *user);
void	get_rays(t_user *user);

#endif