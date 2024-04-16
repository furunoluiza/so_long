/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_playable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:05:50 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/10 18:05:52 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void fill_map(t_map *copy_map, int x, int y)
{
    if (x == copy_map->x_player && y == copy_map->y_player)
        printf("No começo.\n");
    else
        printf("X: %d, Y: %d.\n", x, y);
    sleep(1);
    if (copy_map->map[x][y] == 'C')
       copy_map->verify_collectible--;
    if (copy_map->map[x][y] == 'E')
    {
        copy_map->verify_exit = 1;
        copy_map->map[x][y] = '1';
    }
    if (x < 1 || x > copy_map->width || y < 1 || y > copy_map->height
        || copy_map->map[x][y] == '1')
        return ;
    copy_map->map[x][y] = '1';
    fill_map(copy_map, x - 1, y);
    fill_map(copy_map, x + 1, y);
    fill_map(copy_map, x, y - 1);
    fill_map(copy_map, x, y + 1);
}

int playable_map(char **map)
{
    t_map   *copy_map;

    copy_map = struct_map(map);
    fill_map(copy_map, copy_map->x_player, copy_map->y_player);
    if (copy_map->verify_collectible != 0 || copy_map->verify_exit == 0)
        return(PLAYABLE_ERROR);
    free_matrix(copy_map->map);
    free(copy_map);
    return (NONE_ERROR);
}
