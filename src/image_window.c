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

static void image_to_window(t_all *info, int i, int j, char c)
{
    if (c == 'P')
        mlx_put_image_to_window(info->mlxi, info->mlx_window,
         info->pl_left, j * 64, i * 64);
    else if (c == '1')
        mlx_put_image_to_window(info->mlxi, info->mlx_window,
         info->wall, j * 64, i * 64);
    else if (c == '0')
        mlx_put_image_to_window(info->mlxi, info->mlx_window,
         info->space, j * 64, i * 64);
    else if (c == 'C')
        mlx_put_image_to_window(info->mlxi, info->mlx_window,
         info->collectible, j * 64, i * 64);
    else if (c == 'E')
        mlx_put_image_to_window(info->mlxi, info->mlx_window,
         info->exit, j * 64, i * 64);
}

int    populate_window(t_all *info)
{
    int i;
    int j;

    i = 0;
    while (info->map[i])
    {
        j = 0;
        while (info->map[i][j])
        {
            image_to_window(info, i, j, info->map[i][j]);
            j++;
        }
        i++;
    }
    return (0);
}