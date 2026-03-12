/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:30:19 by jromann           #+#    #+#             */
/*   Updated: 2026/03/12 15:57:08 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

size_t	skip_spaces(char *str)
{
	size_t	iter;

	iter = 0;
	while (str[iter] && str[iter] == ' ')
		iter++;
	return (iter);
}

void	parse_info(t_user *user)
{
	size_t	iter;

	iter = 0;
	while (user->info[iter])
	{
		if (((ft_strncmp("NO ", user->info[iter], 3) == 0) && (!user->path.no))
			|| ((ft_strncmp("SO ", user->info[iter], 3) == 0)
				&& (!user->path.so)) || ((ft_strncmp("WE ", user->info[iter],
						3) == 0) && (!user->path.we)) || ((ft_strncmp("EA ",
						user->info[iter], 3) == 0) && (!user->path.ea)))
			extract_line(user, iter);
		else if ((ft_strncmp("F", user->info[iter], 1) == 0
				&& user->floor.blue == -1) || (ft_strncmp("C", user->info[iter],
					1) == 0 && user->ceiling.blue == -1))
			color_info(user, user->info[iter][0], iter);
		else if (user->info[iter][skip_spaces(user->info[iter])] == '1')
			return ;
		else
			exit_game(user, ERROR, "Error\nInvalid input!");
		iter++;
	}
}
