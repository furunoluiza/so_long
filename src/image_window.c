/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:42:50 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/19 12:42:56 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void image_to_window(t_cluster *info, int i, int j, char c)
{
    //write(1, "oi\n", 2);
    if (c == 'P')
        mlx_put_image_to_window(info->window->mlxi, info->window->mlx_window,
         info->image->pl_left, j * 64, i * 64);
    else if (c == '1')
        mlx_put_image_to_window(info->window->mlxi, info->window->mlx_window,
         info->image->wall, j * 64, i * 64);
    else if (c == '0')
        mlx_put_image_to_window(info->window->mlxi, info->window->mlx_window,
         info->image->space, j * 64, i * 64);
    else if (c == 'C')
        mlx_put_image_to_window(info->window->mlxi, info->window->mlx_window,
         info->image->collectible, j * 64, i * 64);
    else if (c == 'E')
        mlx_put_image_to_window(info->window->mlxi, info->window->mlx_window,
         info->image->exit, j * 64, i * 64);
}

int    populate_window(t_cluster *info)
{
    int i;
    int j;

    i = 0;
    while (info->window->map[i])
    {
        j = 0;
        printf("-> %s", info->window->map[i]);
        while (info->window->map[i][j])
        {
            image_to_window(info, i, j, info->window->map[i][j]);
            j++;
        }
        i++;
    }
    mlx_loop(info->window->mlxi);
    return (0);
}