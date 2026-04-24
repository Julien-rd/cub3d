/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:29:29 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/21 14:31:34 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	validate_file_extension(t_user *user, char *file_name)
{
	char	*ret;

	if (!file_name || !file_name[0])
		exit_game(user, ERROR, "Error\nEmpty argument");
	ret = ft_strchr(file_name, ' ');
	if (ret)
		exit_game(user, ERROR, "Error\nSpaces in file name");
	ret = ft_strrchr(file_name, '.');
	if (!ret)
		exit_game(user, ERROR, "Error\nInvalid input format");
	if (ft_strlen(ret) != 4 || ft_strncmp(ret, ".cub", 4))
		exit_game(user, ERROR, "Error\nInvalid input format");
	if (ft_strlen(file_name) > 5)
	{
		if (ft_strchr(ret -1, '/'))
			exit_game(user, ERROR, "Error\nInvalid input format");
	}
	else
		exit_game(user, ERROR, "Error\nInvalid input format");
}
