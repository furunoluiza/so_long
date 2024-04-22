/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:27:11 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/22 14:27:26 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int verify_move(t_all *all, int height, int width)
{
    if (all->map[height][width] == 'E')
    {
        if (all->num_collectible == 0)
        {
            mlx_destroy_window(all->mlxi, all->mlx_window);
            //free_all(all);
            exit(0);
        }
        else
            return(0);
    }
    else if (all->map[height][width] == '1')
        return (0);
    return (1);
}

static int move_player_up(t_all *all)
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
    }
    return (0);
}

static int move_player_down(t_all *all)
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
    }
    return (0);
}

static int move_player_right(t_all *all)
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
    }
    return (0);
}

static int move_player_left(t_all *all)
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
    }
    return (0);
}

int set_hooks(int key, t_all *all)
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
        mlx_destroy_window(all->mlxi, all->mlx_window);
        //free_all(all);
        exit(0);
    }
    return (0);
}