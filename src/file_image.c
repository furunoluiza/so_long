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

static t_window    *struct_window(t_map *map)
{
    t_window    *window;

    window = ft_calloc(1, sizeof(t_window));
    window->mlxi = mlx_init();
    if (!window->mlxi)
	{
		free(window);
		return (NULL);
	}
    window->width = map->width;
	window->height = map->height;
	window->mlx_window = mlx_new_window(window->mlxi,
        64 * window->width, 64 * window->height, "so_long");
    return (window);
}

static t_image	*struct_image(t_window *window)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	image->window = window;
	image->pl_left = mlx_xpm_file_to_image(image->window->mlxi,
			"textures/frog_left.xpm", &x, &y);
	return (image);
}

void    file_image(char **map)
{
    t_map   *info_map;
    t_window    *window;
    t_image     *image;
    t_list      *list;

    info_map = struct_map(map);
    window = struct_window(info_map);
    image = struct_image(window);
    list = put_all_together(info_map, window, image);
}