/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:29:29 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/20 16:24:04 by vmanuyko         ###   ########.fr       */
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

	if (!file_name || !file_name[0])
		error_exit("Error\nEmpty argument");
	ret = ft_strchr(file_name, ' ');
	if (ret)
		error_exit("Error\nSpaces in file name");
	ret = ft_strrchr(file_name, '.');
	if (!ret)
		error_exit("Error\nInvalid input format");
	if (ft_strlen(ret) != 4 || ft_strncmp(ret, ".cub", 4))
		error_exit("Error\nInvalid input format");
	if (ft_strlen(file_name) > 5)
	{
		if (ft_strchr(ret -1, '/'))
			error_exit("Error\nInvalid input format");
	}
	else
		error_exit("Error\nInvalid input format");
}
