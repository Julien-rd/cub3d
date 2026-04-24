/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:44:19 by jromann           #+#    #+#             */
/*   Updated: 2026/04/21 16:18:09 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	s_atoi(const char *str)
{
	int	i;
	int	sign;
	int	return_number;

	i = 0;
	sign = 1;
	return_number = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		return_number *= 10;
		return_number += str[i] - 48;
		i++;
	}
	if (i == 0)
		return (-1);
	return_number *= sign;
	if (return_number > 255)
		return (-1);
	return (return_number);
}
