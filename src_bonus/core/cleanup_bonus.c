/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:14:03 by jromann           #+#    #+#             */
/*   Updated: 2026/03/17 11:27:01 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	free2d(char **str)
{
	size_t	iter;

	iter = 0;
	if (!str)
		return ;
	while (str[iter])
	{
		free(str[iter]);
		iter++;
	}
	free(str);
}

void	cleanup_mlx(t_user *user)
{
	if (user->tex.n.img)
		mlx_destroy_image(user->mlx, user->tex.n.img);
	if (user->tex.s.img)
		mlx_destroy_image(user->mlx, user->tex.s.img);
	if (user->tex.w.img)
		mlx_destroy_image(user->mlx, user->tex.w.img);
	if (user->tex.e.img)
		mlx_destroy_image(user->mlx, user->tex.e.img);
	if (user->tex.d.img)
		mlx_destroy_image(user->mlx, user->tex.d.img);
	if (user->tex.img.img)
		mlx_destroy_image(user->mlx, user->tex.img.img);
	if (user->mlx_win)
		mlx_destroy_window(user->mlx, user->mlx_win);
	if (user->mlx)
	{
		mlx_destroy_display(user->mlx);
		free(user->mlx);
	}
}

void	exit_game(t_user *user, int flag, char *msg)
{
	cleanup_mlx(user);
	free2d(user->info);
	free2d(user->map);
	if (flag == PERROR || flag == ERROR)
	{
		if (msg != NULL && flag == PERROR)
			perror(msg);
		if (msg != NULL && flag == ERROR)
			ft_putendl_fd(msg, 2);
		exit(1);
	}
	exit(0);
}
