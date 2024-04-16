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
        matrix[i] = NULL;
        i--;
    }
    free(matrix);
    matrix = NULL;
}    

static char    *copy_array(char *line)
{
    int i;
    char    *copy_line;

    i = 0;
    while (line[i])
        i++;
    copy_line = (char *)ft_calloc((i + 1), sizeof(char));
    if (!copy_line)
    {
        free(copy_line);
        return (NULL);
    }
    while (line[i])
    {
        copy_line[i] = line[i];
        i++;
    }
    copy_line[i] = '\0';
    return (copy_line);
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
    i = 0;
    while (map[i])
    {
        copy_map[i] = copy_array(map[i]);
        i++;
    }
    return (copy_map);
}

