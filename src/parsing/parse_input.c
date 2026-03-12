/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:11:39 by jromann           #+#    #+#             */
/*   Updated: 2026/03/12 15:55:08 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	final_check(t_user *user)
{
	if (user->path.we == NULL || user->path.so == NULL || user->path.ea == NULL
		|| user->path.no == NULL)
		exit_game(user, ERROR, "Error\nNo path found!");
	if (user->start_dir == 'D')
		exit_game(user, ERROR, "Error\nNo direction found!");
	if (user->floor.red == -1 || user->floor.blue == -1
		|| user->floor.green == -1)
		exit_game(user, ERROR, "Error\nNo color found!");
	if (user->ceiling.red == -1 || user->ceiling.blue == -1
		|| user->ceiling.green == -1)
		exit_game(user, ERROR, "Error\nNo color found!");
	if (!user->info || !user->map)
		exit_game(user, ERROR, "Error\nInvalid input!");
}

static unsigned int	extract_color(t_rgb color)
{
	return ((color.red << 16) | (color.green << 8) | color.blue);
}

static void	convert_color(t_user *user)
{
	user->ceiling.colour = extract_color(user->ceiling);
	user->floor.colour = extract_color(user->floor);
}

static void	fill_spaces_with_walls(t_user *user)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (user->map[y])
	{
		x = 0;
		while (user->map[y][x])
		{
			if (user->map[y][x] == ' ')
				user->map[y][x] = '1';
			x++;
		}
		y++;
	}
}

int	parse_input(char *file_name, t_user *user)
{
	char	*input;

	input = read_file_to_string(file_name);
	if (!input)
		exit_game(user, ERROR, "Error\nEmpty file !\n");
	create_and_validate_map(input, user);
	parse_info(user);
	final_check(user);
	fill_spaces_with_walls(user);
	convert_color(user);
	return (0);
}
