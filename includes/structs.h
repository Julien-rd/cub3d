/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:19:39 by jromann           #+#    #+#             */
/*   Updated: 2026/03/24 14:38:50 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>
# include "input_keys.h"

typedef struct s_rgb
{
	int				red;
	int				green;
	int				blue;
	unsigned int	colour;
}	t_rgb;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_image
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		line;
	int		endian;
}	t_image;

typedef struct s_texture
{
	t_image	n;
	t_image	s;
	t_image	w;
	t_image	e;
	t_image	img;
}	t_texture;

typedef struct s_path
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_path;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
}	t_player;

typedef struct s_dda	t_dda;

typedef struct s_user
{
	char		start_dir;
	t_player	player;
	t_vector	plane;
	char		**map;
	char		**info;
	t_dda		*ray;
	t_path		path;
	t_rgb		floor;
	t_rgb		ceiling;
	void		*mlx;
	void		*mlx_win;
	t_texture	tex;
	t_keys		key;
}	t_user;

#endif