/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:02:58 by jromann           #+#    #+#             */
/*   Updated: 2026/03/12 15:57:15 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	check_extensions(t_user *user, char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 5)
		exit_game(user, ERROR, "Error\nWrong path extension!");
	if (ft_strncmp(".xpm", &path[len - 4], 4) != 0)
		exit_game(user, ERROR, "Error\nWrong path extension!");
}

void	extract_line(t_user *user, size_t pos)
{
	size_t	start;
	size_t	end;

	start = 2;
	while (user->info[pos][start] == ' ')
		start++;
	end = ft_strlen(user->info[pos]) - 1;
	while (user->info[pos][end] == ' ')
		end--;
	user->info[pos][end + 1] = '\0';
	check_extensions(user, &user->info[pos][start]);
	if (user->info[pos][0] == 'N')
		user->path.no = &user->info[pos][start];
	if (user->info[pos][0] == 'S')
		user->path.so = &user->info[pos][start];
	if (user->info[pos][0] == 'W')
		user->path.we = &user->info[pos][start];
	if (user->info[pos][0] == 'E')
		user->path.ea = &user->info[pos][start];
}
