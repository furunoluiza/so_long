/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:42:50 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/19 12:42:56 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void image_to_window(t_all *info, int i, int j, char c)
{
    if (c == 'P')
        mlx_put_image_to_window(info->mlxi, info->mlx_window,
         info->pl_right, j * 64, i * 64);
    else if (c == '1')
        mlx_put_image_to_window(info->mlxi, info->mlx_window,
         info->wall, j * 64, i * 64);
    else if (c == '0')
        mlx_put_image_to_window(info->mlxi, info->mlx_window,
         info->space, j * 64, i * 64);
    else if (c == 'C')
        mlx_put_image_to_window(info->mlxi, info->mlx_window,
         info->collectible, j * 64, i * 64);
    else if (c == 'E')
        mlx_put_image_to_window(info->mlxi, info->mlx_window,
         info->exit, j * 64, i * 64);
}

int    populate_window(t_all *info)
{
    int i;
    int j;

    i = 0;
    while (info->map[i])
    {
        j = 0;
        while (info->map[i][j])
        {
            image_to_window(info, i, j, info->map[i][j]);
            j++;
        }
        i++;
    }
    return (0);
}

static void	struct_image(t_all *all)
{
    int     height;
    int     width;

	all->pl_left = mlx_xpm_file_to_image(all->mlxi,
			"./textures/frog/frog_left.xpm", &height, &width);
    all->pl_right = mlx_xpm_file_to_image(all->mlxi,
			"./textures/frog/frog_right.xpm", &height, &width);
    all->pl_left_att = mlx_xpm_file_to_image(all->mlxi,
			"./textures/frog/frog_left_attack.xpm", &height, &width);
    all->pl_right_att = mlx_xpm_file_to_image(all->mlxi,
			"./textures/frog/frog_right_attack.xpm", &height, &width);
    all->wall = mlx_xpm_file_to_image(all->mlxi,
			"./textures/wall/wall.xpm", &height, &width);
    all->exit = mlx_xpm_file_to_image(all->mlxi,
			"./textures/exit/exit.xpm", &height, &width);
    all->space = mlx_xpm_file_to_image(all->mlxi,
			"./textures/empty_space/empty_space.xpm", &height, &width);
    all->collectible = mlx_xpm_file_to_image(all->mlxi,
			"./textures/collectible/collectible.xpm", &height, &width);
}

t_all    *struct_all(char **map)
{
    t_all   *all;

    all = malloc(sizeof(t_all));
    all->map = map;
    all->mlxi = mlx_init();
    if (!all->mlxi)
	{
		free(all);
		return (NULL);
	}
    all->width = width(map) - 1;
	all->height = height(map);
    all->x_player = xy_player(map, 'x');
    all->y_player = xy_player(map, 'y');
    all->num_collectible = count_character(map, 'C');
    all->count_moves = 0;
	all->mlx_window = mlx_new_window(all->mlxi,
        64 * all->width, 64 * all->height, "so_long");
    struct_image(all);
    return (all);
}