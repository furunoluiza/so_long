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

static void move_player_up(t_all *all)
{

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
        free_all(all);
        exit(0);
    }
    return (0);
}