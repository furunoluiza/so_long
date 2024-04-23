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
# define ESC 65307
# define UP 65362
# define W 119
# define DOWN 65364
# define S 115
# define RIGHT 65363
# define D 100
# define LEFT 65361
# define A 97

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

typedef struct s_all
{
    char    **map;
    int     height;
    int     width;
    int     x_player;
    int     y_player;
    int     num_collectible;
    int     count_moves;
    void    *mlxi;
    void    *mlx_window;
    void    *pl_left;
    void    *pl_right;
    void    *pl_left_att;
    void    *pl_right_att;
    void    *wall;
    void    *exit;
    void    *space;
    void    *collectible;
}           t_all;

/* so_long functions */
void free_matrix(char **matrix);
char **open_fd(char *map_ext);
char **copy_matrix(char **map);
int height(char **map);
int width(char  **map);
int	xy_player(char **map, char axis);
int populate_window(t_all *info);
int set_hooks(int key, t_all *all);
int move_player_up(t_all *all);
int move_player_down(t_all *all);
int move_player_right(t_all *all);
int move_player_left(t_all *all);
int verify_move(t_all *all, int height, int width);
int free_all(t_all *all);
t_map   *struct_map(char **map);
t_all   *struct_all(char **map);

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