/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:36:22 by jromann           #+#    #+#             */
/*   Updated: 2026/04/15 15:57:27 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static bool	is_empty_line(char *line)
{
	size_t	iter;

	iter = 0;
	while (line[iter] == 32)
		iter++;
	if (line[iter] == '\n')
		return (true);
	return (false);
}

void	check_empty_lines(char *map, char *input, t_user *user)
{
	size_t	iter;
	bool	empty_line;

	empty_line = false;
	iter = 0;
	while (map[iter])
	{
		if (is_empty_line(&map[iter]))
			empty_line = true;
		else
		{
			if (empty_line == true)
				return (free(input), exit_game(user, ERROR,
						"Empty line in map"));
		}
		while (map[iter] != '\n' && map[iter])
			iter++;
		if (map[iter] != '\0')
			iter++;
	}
}

size_t	map_exists(char *input, t_user *user)
{
	size_t	iter;
	size_t	offset;

	iter = 0;
	while (input[iter])
	{
		if (input[iter] == '\n')
		{
			iter++;
			offset = 0;
			while (input[iter + offset] == 32)
				offset++;
			if (input[iter + offset] == '1')
				return (iter);
		}
		else
			iter++;
	}
	free(input);
	exit_game(user, ERROR, "No map found");
	return (0);
}
