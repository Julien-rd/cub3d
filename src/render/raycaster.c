/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:47:08 by jromann           #+#    #+#             */
/*   Updated: 2026/03/19 17:42:51 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

void	draw_image(t_user *user)
{
	int x;
	t_dda	ray;
	
	x = 0;
	ft_bzero(&ray, sizeof(t_dda));
	while (x < SCREEN_WIDTH)
	{
		init_ray(user, &ray, x);
		x++;
	}
}
