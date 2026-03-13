/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:21:15 by jromann           #+#    #+#             */
/*   Updated: 2026/03/12 08:36:29 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_user	user;

	if (argc != 2)
		return (ft_putendl_fd("Error\nInvalid number of arguments!", 2), 1);
	init_data(&user);
	validate_file_extension(argv[1]);
	parse_input(argv[1], &user);
	init_graphics(&user);
	start_game(&user);
	exit_game(&user, SUCCESS, NULL);
	return (0);
}
