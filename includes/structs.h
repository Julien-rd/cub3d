/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:19:39 by jromann           #+#    #+#             */
/*   Updated: 2026/03/12 16:41:54 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

typedef struct s_rgb
{
	int				red;
	int				green;
	int				blue;
	unsigned int	colour;
}	t_rgb;

typedef struct s_keys
{
	bool			w;
	bool			s;
	bool			a;
	bool			d;
	bool			arr_l;
	bool			arr_r;
	int				mouse_pos;
}	t_keys;

typedef struct s_coord
{
	double			x;
	double			y;
}	t_coord;

typedef struct s_image
{
	void			*img;
	char			*data;
	int				width;
	int				height;
	int				bpp;
	int				line;
	int				endian;
}	t_image;

typedef struct s_texture
{
	t_image			n;
	t_image			s;
	t_image			w;
	t_image			e;
	t_image			img;
}	t_texture;


typedef struct s_draw_utils
{
	int				start;
	int				end;
	t_image		*texture;
	double			wall_x;
	int				tex_x;
}	t_draw_utils;

typedef struct s_dda
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			pos_x;
	double			pos_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	double			perp_wall_dist;
}	t_dda;

typedef struct s_path
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
}	t_path;

typedef struct s_user
{
	char			start_dir;
	t_coord			player_pos;
	t_coord			dir_vec;
	t_coord			plane_vec;
	char			**map;
	char			**info;
	t_path			path;
	t_rgb			floor;
	t_rgb			ceiling;
	void			*mlx;
	void			*mlx_win;
	t_texture		n_tex;
	t_texture		s_tex;
	t_texture		w_tex;
	t_texture		e_tex;
	void			*img;
	t_image			image;
	t_keys			key;
}					t_user;

#endif