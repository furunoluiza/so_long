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
    t_all   *all;
 
    if (argc != 2)
        return (error_messages(ARGS_ERROR));
    map = open_fd(argv[1]);
    if (check_errors(map) != NONE_ERROR)
        return(free_matrix(map), 1);
    all = struct_all(map);
    populate_window(all);
    mlx_key_hook(all->mlx_window, set_hooks, all);
	mlx_hook(all->mlx_window, 17, 0, free_all, all);
    mlx_loop(all->mlxi);
    free_matrix(map);
    return (0);
}