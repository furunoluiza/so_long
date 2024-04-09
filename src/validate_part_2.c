/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_part_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:04:51 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/09 13:04:55 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int wall_horizontal(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i][j])
    {
        if (map[i][j] != '0')
            return (1);
        j++;  
    }
    while (map[i])
        i++;
    i--;
    j = 0;
    while (map[i][j])
    {
        if (map[i][j] != '0')
            return (1);
        j++;
    }
    return (0);
}

static int wall_vertical(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i][j])
        j++;
    while (map[i])
    {
        if (map[i][0] != '0')
            return (1);
        i++;
    }
    i = 0;
    while (map[i])
    {
        if (map[i][j - 1] != '0')
            return (1);
        i++;
    }
    return (0);
}

int check_wall(char **map)
{
    if (wall_horizontal(map) || wall_vertical(map))
        return (WALL_ERROR);
    return (NONE_ERROR);
}