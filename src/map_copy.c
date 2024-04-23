/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:05:09 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/10 18:05:14 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_matrix(char **matrix)
{
    int i;

    i = 0;
    while (matrix[i])
        i++;
    while (i >= 0)
    {
        free(matrix[i]);
        i--;
    }
    free(matrix);
}

static char    **copy_array(char **map, char **copy_map, int i)
{
    int j;

    j = 0;
    while (map[i][j])
        j++;
    copy_map[i] = ft_calloc((j + 1), sizeof(char));
    if (!copy_map[i])
    {
        free_matrix(copy_map);
        return (NULL);
    }
    j = 0;
    while (map[i][j])
    {
        copy_map[i][j] = map[i][j];
        j++;
    }
    copy_map[i][j] = '\0';
    return (copy_map);
}

char **copy_matrix(char **map)
{
    int     i;
    char    **copy_map;

    i = 0;
    while (map[i])
        i++;
    copy_map = (char **)ft_calloc((i + 1), sizeof(char *));
    if (!copy_map)
        return (NULL);
    copy_map[i] = NULL;
    i = 0;
    while (map[i])
    {
        copy_map = copy_array(map, copy_map, i);
        i++;
    }
    return (copy_map);
}

