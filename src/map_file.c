/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:05:21 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/10 19:20:04 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int     number_lines_fd(char *map_ext)
{
    int     number_lines;
    int     fd;
    char    *line;

    number_lines = 0;
    fd = open(map_ext, O_RDWR);
    if (fd < 0)
    {
        error_messages(FD_ERROR);
        exit(0);
    }
    line = get_next_line(fd);
    while (line != NULL)
    {
        free(line);
        line = get_next_line(fd);
        number_lines += 1;
    }
    close(fd);
    return (number_lines);
}

static char    **read_fd(char *map_ext)
{
    int     i;
    int     num_lines;
    int     fd;
    char    **map;

    i = 0;
    num_lines = number_lines_fd(map_ext);
    map = malloc(sizeof(char *) * (num_lines + 1));
    if (!map)
    {
        error_messages(FD_ERROR);
        exit(0);
    }
    fd = open(map_ext, O_RDWR);
    while (i <= num_lines)
    {
        map[i] = get_next_line(fd);
        i++;
    }
	//get_next_line(fd);
    map[i] = NULL;
    close(fd);
    return (map);
}

char **open_fd(char *map_ext)
{
    char    **map;

    if (check_extension(map_ext) == EXTENSION_ERROR)
    {
        error_messages (EXTENSION_ERROR);
        exit(0);
    }
    map = read_fd(map_ext);
    //printf("-> %s", map[2]);
    return (map);
}
