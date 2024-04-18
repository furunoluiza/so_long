/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:15:51 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/08 15:15:53 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    char    **map;
    //int     i = 0;
 
    if (argc != 2)
        return (error_messages(ARGS_ERROR));
    map = open_fd(argv[1]);
    /*while (map[i])
    {
        printf("-> %s", map[i]);
        //printf("len: %li\n", ft_strlen(map[i]));
        i++;
    }*/
    if (check_errors(map) != NONE_ERROR)
        return(free_matrix(map), 1);
    file_map(map);
    free_matrix(map);
    return (0);
}