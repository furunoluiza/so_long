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