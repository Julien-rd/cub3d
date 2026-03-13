/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:29:29 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/12 14:25:47 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	error_exit(char *mes)
{
	ft_putendl_fd(mes, 2);
	exit(1);
}

void	validate_file_extension(char *file_name)
{
	char	*ret;

	ret = ft_strnstr(file_name, ".cub", ft_strlen(file_name));
	if (!ret)
		error_exit("Error\ninvalid input format");
	if (ft_strlen(ret) > 4)
		error_exit("Error\ninvalid input format");
	ret = ft_strrchr(file_name, '/');
	if (ret)
	{
		if (ft_strlen(ret + 1) < 5)
			error_exit("Error\ninvalid input format");
	}
	if (ft_strlen(file_name) < 5)
		error_exit("Error\ninvalid input format");
}
