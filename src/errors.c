/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:03:08 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/09 17:03:11 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int error_messages(int error)
{
    ft_putstr_fd("Error\n", 2);
    if (error == -1)
        ft_putstr_fd("Wrong numbers of arguments, expected 2.\n", 2);
    else if (error == -2)
        ft_putstr_fd("Invalid extension path, expected .ber file.\n", 2);
    else if (error == - 3)
        ft_putstr_fd("Error opening the map file.\n", 2);
    else if (error == -4)
        ft_putstr_fd("Invalid characters, must have one player and one exit, and at least one collectible.\n", 2);
    else if (error == -5)
        ft_putstr_fd("The map is not retangular.\n", 2);
    else if (error == -6)
        ft_putstr_fd("The map is not surrounded by walls.\n", 2);
    else if (error == -7)
        ft_putstr_fd("The map has no valid path for winning.\n", 2);
    return (error);
}

int check_errors(char **map)
{
    if (number_character(map) == CHARACTER_ERROR || map_characters(map) == CHARACTER_ERROR)
        return (error_messages(CHARACTER_ERROR));
    else if (rectangular_map(map) == RECTANGULAR_ERROR)
        return (error_messages(RECTANGULAR_ERROR));
    else if (check_wall(map) == WALL_ERROR)
        return (error_messages(WALL_ERROR));
    else if (playable_map(map) == PLAYABLE_ERROR)
        return (error_messages(PLAYABLE_ERROR));
    return (NONE_ERROR);
}