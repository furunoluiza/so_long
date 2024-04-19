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
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include <fcntl.h>

#include <stdio.h> //apagar??

/* errors */
# define NONE_ERROR 1
# define ARGS_ERROR -1
# define EXTENSION_ERROR -2
# define FD_ERROR -3
# define CHARACTER_ERROR -4
# define RECTANGULAR_ERROR -5
# define WALL_ERROR -6
# define PLAYABLE_ERROR -7

/* keymaps */
//# define atalhos do teclado

typedef struct s_map
{
    char    **map;
    int     height;
    int     width;
    int     x_player;
    int     y_player;
    int     num_collectible;
    int     verify_collectible;
    int     verify_exit;
}           t_map;

typedef struct s_window
{
    char    **map;
    int     height;
    int     width;
    void    *mlxi;
    void    *mlx_window;
}           t_window;

typedef struct s_image
{
    t_window    *window;
    char        *pl_left;
    char        *pl_right;
    char        *pl_left_att;
    char        *pl_right_att;
    char        *wall;
    char        *exit;
    char        *space;
    char        *collectible;
}               t_image;

typedef struct s_cluster
{
    t_window    *window;
    t_image     *image;
}               t_cluster;

/* map functions */
char **open_fd(char *map_ext);
char **copy_matrix(char **map);
void free_matrix(char **matrix);
int height(char **map);
int width(char  **map);
t_map   *struct_map(char **map);
t_cluster    *file_image(char **map);
int    populate_window(t_cluster *info);

/* validate functions */
int check_errors(char **map);
int error_messages(int error);
int check_extension(char *argv);
int number_character(char **map);
int count_character(char **map, char c);
int map_characters(char **map);
int rectangular_map(char **map);
int check_wall(char **map);
int playable_map(char **map);

#endif