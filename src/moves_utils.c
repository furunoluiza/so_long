/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:20:48 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/23 12:20:50 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move_player_up(t_all *all)
{   
    int width;
    int height; 

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
        all->count_moves += 1;
        ft_putnbr_fd(all->count_moves, 1);
        ft_putchar_fd('\n', 1);
    }
    return (0);
}

int move_player_down(t_all *all)
{   
    int width;
    int height; 

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
        all->count_moves += 1;
        ft_putnbr_fd(all->count_moves, 1);
        ft_putchar_fd('\n', 1);
    }
    return (0);
}

int move_player_right(t_all *all)
{   
    int width;
    int height; 

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
        all->count_moves += 1;
        ft_putnbr_fd(all->count_moves, 1);
        ft_putchar_fd('\n', 1);
    }
    return (0);
}

int move_player_left(t_all *all)
{   
    int width;
    int height; 

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
        all->count_moves += 1;
        ft_putnbr_fd(all->count_moves, 1);
        ft_putchar_fd('\n', 1);
    }
    return (0);
}