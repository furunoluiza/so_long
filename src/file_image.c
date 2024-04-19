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

static t_window    *struct_window(char **map)
{
    t_window    *window;

    window = ft_calloc(1, sizeof(t_window));
    window->map = map;
    window->mlxi = mlx_init();
    if (!window->mlxi)
	{
		free(window);
		return (NULL);
	}
    window->width = width(map);
	window->height = height(map);
	window->mlx_window = mlx_new_window(window->mlxi,
        64 * window->width, 64 * window->height, "so_long");
    return (window);
}

static t_image	*struct_image(t_window *window)
{
    int     height;
    int     width;
	t_image	*image;

	image = malloc(sizeof(t_image));
	image->window = window;
	image->pl_left = mlx_xpm_file_to_image(image->window->mlxi,
			"../textures/frog/frog_left.xpm", &height, &width);
    image->pl_right = mlx_xpm_file_to_image(image->window->mlxi,
			"../textures/frog/frog_right.xpm", &height, &width);
    image->pl_left_att = mlx_xpm_file_to_image(image->window->mlxi,
			"../textures/frog/frog_left_attack.xpm", &height, &width);
    image->pl_right_att = mlx_xpm_file_to_image(image->window->mlxi,
			"../textures/frog/frog_right_attack.xpm", &height, &width);
    image->wall = mlx_xpm_file_to_image(image->window->mlxi,
			"../textures/wall/wall.xpm", &height, &width);
    image->exit = mlx_xpm_file_to_image(image->window->mlxi,
			"../textures/exit/exit.xpm", &height, &width);
    image->space = mlx_xpm_file_to_image(image->window->mlxi,
			"../textures/empty_space/empty_space.xpm", &height, &width);
    image->collectible = mlx_xpm_file_to_image(image->window->mlxi,
			"../textures/collectible/collectible.xpm", &height, &width);
	return (image);
}

static t_cluster   *cluster_structs(t_window *window, t_image *image)
{
    t_cluster   *info;

    info = malloc(sizeof(t_cluster));
    info->window = window;
    info->image = image;
    return (info);
}

t_cluster    *file_image(char **map)
{
    //int i = 0;
    t_window    *window;
    t_image     *image;
    t_cluster      *info;

    window = struct_window(map);
    image = struct_image(window);
    info = cluster_structs(window, image);
    /*while (window->map[i])
    {
        printf("-> %s", window->map[i]);
        //printf("len: %li\n", ft_strlen(map[i]));
        i++;
    }*/
    return (info);
}