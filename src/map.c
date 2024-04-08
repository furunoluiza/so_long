/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:06:33 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/08 16:06:35 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int error_messages(int error)
{
    ft_putstr_fd("Error\n", 2);
    if (error == -1)
        ft_putstr_fd("Wrong numbers of arguments, expected 2\n", 2);
    else if (error == -2)
        ft_putstr_fd("Invalid extension path, expected .ber file\n", 2);
    else if (error == -3)
        ft_putstr_fd("Invalid characters, must have one player and one exit, and at least one collectible\n", 2);
    else if (error == -4)
        ft_putstr_fd("The map is not retangular\n", 2);
}

 