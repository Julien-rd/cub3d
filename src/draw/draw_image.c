/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:44:11 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/20 14:44:13 by vmanuyko         ###   ########.fr       */
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
