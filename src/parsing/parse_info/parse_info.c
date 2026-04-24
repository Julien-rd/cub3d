/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:30:19 by jromann           #+#    #+#             */
/*   Updated: 2026/04/23 15:41:21 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

size_t	skip_spaces(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

void	parse_info(t_user *user)
{
	size_t	i;

	i = 0;
	while (user->info[i])
	{
		if (((ft_strncmp("NO ", user->info[i], 3) == 0) && (!user->path.no))
			|| ((ft_strncmp("SO ", user->info[i], 3) == 0)
				&& (!user->path.so)) || ((ft_strncmp("WE ", user->info[i],
						3) == 0) && (!user->path.we)) || ((ft_strncmp("EA ",
						user->info[i], 3) == 0) && (!user->path.ea)))
			extract_line(user, i);
		else if ((ft_strncmp("F ", user->info[i], 2) == 0
				&& user->floor.blue == -1) || (ft_strncmp("C ", user->info[i],
					2) == 0 && user->ceiling.blue == -1))
			color_info(user, user->info[i][0], i);
		else if (user->info[i][skip_spaces(user->info[i])] == '1')
			return ;
		else
			exit_game(user, ERROR, "Invalid info in provided file");
		i++;
	}
}
