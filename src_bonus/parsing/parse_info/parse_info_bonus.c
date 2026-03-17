/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:30:19 by jromann           #+#    #+#             */
/*   Updated: 2026/03/17 11:37:35 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

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
						user->info[iter], 3) == 0) && (!user->path.ea))
			|| ((ft_strncmp("DR ", user->info[iter], 3) == 0)
				&& (!user->path.dr)))
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
