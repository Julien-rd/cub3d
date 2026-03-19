/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:17:32 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/19 19:19:46 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

void	ft_put_pixel(int x, int y, t_user *user, unsigned int colour)
{
	int	pos;

	pos = x * (user->tex.img.bpp / 8) + y * user->tex.img.line;
	*(unsigned int *)(user->tex.img.data + pos) = colour;
}

// void	minimap(t_user *user)
// {
	
// }
