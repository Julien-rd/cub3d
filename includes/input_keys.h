/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:23:03 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/17 15:24:59 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_KEYS_H
# define INPUT_KEYS_H

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ARR_R 65363
# define KEY_ARR_L 65361

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

#endif