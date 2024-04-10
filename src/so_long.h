/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:19:57 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/08 14:23:01 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define S0_LONG_H

# include "../libs/libft/libft.h"
# include <fcntl.h>

#include <stdio.h>

/* errors */
# define NONE_ERROR 1
# define ARGS_ERROR -1
# define EXTENSION_ERROR -2
# define FD_ERROR -3
# define CHARACTER_ERROR -4
# define RECTANGULAR_ERROR -5
# define WALL_ERROR -6



/* keymaps */
# define atalhos do teclado

/* map functions */
char **open_fd(char *map_ext);
char **copy_matrix(char **map)

/* validate functions */
int check_errors(char **map);
int error_messages(int error);
int check_extension(char *argv);
int number_character(char **map);
int map_characters(char **map);
int rectangular_map(char **map);
int check_wall(char **map);

#endif