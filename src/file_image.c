/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:24:02 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/18 17:24:18 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	all->mlx_window = mlx_new_window(all->mlxi,
        64 * all->width, 64 * all->height, "so_long");
    struct_image(all);
    return (all);
}