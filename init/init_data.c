/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:38:38 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/11 13:12:45 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	intialise_data(t_user *user)
{
	ft_bzero(user, sizeof(t_user));
	user->start_dir = 'D';
	user->floor.red = -1;
	user->floor.blue = -1;
	user->floor.green = -1;
	user->ceiling.red = -1;
	user->ceiling.blue = -1;
	user->ceiling.green = -1;
	user->vars.mouse_pos = SCREEN_WIDTH / 2;
}
