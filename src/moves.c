/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:27:11 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/24 20:03:20 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_all(t_all *all)
{
	if (!all)
		return (0);
	mlx_destroy_image(all->mlxi, all->pl_right_att);
	mlx_destroy_image(all->mlxi, all->wall);
	mlx_destroy_image(all->mlxi, all->exit);
	mlx_destroy_image(all->mlxi, all->space);
	mlx_destroy_image(all->mlxi, all->collectible);
	mlx_destroy_image(all->mlxi, all->player[0]);
	mlx_destroy_image(all->mlxi, all->player[1]);
	mlx_destroy_window(all->mlxi, all->mlx_window);
	mlx_destroy_display(all->mlxi);
	free(all->mlxi);
	free_matrix(all->map);
	free(all);
	exit(1);
}

int	verify_move(t_all *all, int height, int width)
{
	if (all->map[height][width] == 'E')
	{
		if (all->num_collectible == 0)
		{
			free_all(all);
			exit(0);
		}
		else
			return (0);
	}
	else if (all->map[height][width] == '1')
		return (0);
	return (1);
}

int animation_player(t_all *all)
{
	static int	i;
	static int	frames;

	if (frames == 35000)
	{
		all->pl_right = all->player[i];
		i++;
		if (i == 2)
			i = 0;
		frames = 0;
		mlx_put_image_to_window(all->mlxi, all->mlx_window,
			all->pl_right, all->x_player * 64, all->y_player * 64);
	}
	frames++;
	return (1);
}

int	set_hooks(int key, t_all *all)
{
	if (key == UP || key == W)
		move_player_up(all);
	else if (key == DOWN || key == S)
		move_player_down(all);
	else if (key == RIGHT || key == D)
		move_player_right(all);
	else if (key == LEFT || key == A)
		move_player_left(all);
	else if (key == ESC)
	{
		free_all(all);
		exit(0);
	}
	return (0);
}
