/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:19:32 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/24 17:19:40 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_moves(t_all *all)
{
	all->count_moves += 1;
	ft_putstr_fd("Movement: ", 1);
	ft_putnbr_fd(all->count_moves, 1);
	ft_putchar_fd('\n', 1);
}

int	move_player_up(t_all *all)
{
	int	width;
	int	height;

	width = all->x_player;
	height = all->y_player - 1;
	if (verify_move(all, height, width))
	{
		all->y_player -= 1;
		if (all->map[height][width] == 'C')
			all->num_collectible -= 1;
		all->map[height][width] = 'P';
		all->map[height + 1][width] = '0';
		populate_window(all);
		print_moves(all);
	}
	return (0);
}

int	move_player_down(t_all *all)
{
	int	width;
	int	height;

	width = all->x_player;
	height = all->y_player + 1;
	if (verify_move(all, height, width))
	{
		all->y_player += 1;
		if (all->map[height][width] == 'C')
			all->num_collectible -= 1;
		all->map[height][width] = 'P';
		all->map[height - 1][width] = '0';
		populate_window(all);
		print_moves(all);
	}
	return (0);
}

int	move_player_right(t_all *all)
{
	int	width;
	int	height;

	width = all->x_player + 1;
	height = all->y_player;
	if (verify_move(all, height, width))
	{
		all->x_player += 1;
		if (all->map[height][width] == 'C')
			all->num_collectible -= 1;
		all->map[height][width] = 'P';
		all->map[height][width - 1] = '0';
		populate_window(all);
		print_moves(all);
	}
	return (0);
}

int	move_player_left(t_all *all)
{
	int	width;
	int	height;

	width = all->x_player - 1;
	height = all->y_player;
	if (verify_move(all, height, width))
	{
		all->x_player -= 1;
		if (all->map[height][width] == 'C')
			all->num_collectible -= 1;
		all->map[height][width] = 'P';
		all->map[height][width + 1] = '0';
		populate_window(all);
		print_moves(all);
	}
	return (0);
}
