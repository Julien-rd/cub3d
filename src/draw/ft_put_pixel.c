/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:11:44 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/23 12:11:58 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

void	ft_put_pixel(int x, int y, t_user *user, unsigned int colour)
{
	int	pos;

	pos = y * user->tex.img.line + x * (user->tex.img.bpp / 8);
	*(unsigned int *)(user->tex.img.data + pos) = colour;
}
