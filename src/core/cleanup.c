/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:14:03 by jromann           #+#    #+#             */
/*   Updated: 2026/04/22 19:03:46 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free2d(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
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
	int	i;

	i = 0;
	cleanup_mlx(user);
	free2d(user->info);
	free2d(user->map);
	if (user->ray)
	{
		while (i < SCREEN_WIDTH)
			free(user->ray[i++]);
		free(user->ray);
	}
	if (flag == PERROR || flag == ERROR)
	{
		ft_putendl_fd("Error", 2);
		if (msg != NULL && flag == PERROR)
			perror(msg);
		if (msg != NULL && flag == ERROR)
			ft_putendl_fd(msg, 2);
		exit(1);
	}
	exit(0);
}
