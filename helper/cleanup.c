/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:14:03 by jromann           #+#    #+#             */
/*   Updated: 2026/02/02 18:55:32 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	if (user->n_tex.img)
		mlx_destroy_image(user->mlx, user->n_tex.img);
	if (user->s_tex.img)
		mlx_destroy_image(user->mlx, user->s_tex.img);
	if (user->w_tex.img)
		mlx_destroy_image(user->mlx, user->w_tex.img);
	if (user->e_tex.img)
		mlx_destroy_image(user->mlx, user->e_tex.img);
	if (user->img)
		mlx_destroy_image(user->mlx, user->img);
	if (user->mlx_win)
		mlx_destroy_window(user->mlx, user->mlx_win);
	if (user->mlx)
	{
		mlx_destroy_display(user->mlx);
		free(user->mlx);
	}
}

void	cleanup(t_user *user, int flag, char *msg)
{
	cleanup_mlx(user);
	free2d(user->info);
	free2d(user->map);
	if (flag == PERROR || flag == ERROR)
	{
		if (msg != NULL && flag == PERROR)
			perror(msg);
		if (msg != NULL && flag == ERROR)
			write(2, msg, ft_strlen(msg));
		exit(1);
	}
	exit(0);
}
