/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:05:31 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/24 17:32:39 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	width(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
		j++;
	return (j);
}

int	xy_player(char **map, char axis)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (axis == 'x')
					return (j);
				if (axis == 'y')
					return (i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_map	*struct_map(char **map)
{
	t_map	*copy_map;

	copy_map = ft_calloc(1, sizeof(t_map));
	copy_map->map = copy_matrix(map);
	copy_map->height = height(map);
	copy_map->width = width(map);
	copy_map->x_player = xy_player(map, 'x');
	copy_map->y_player = xy_player(map, 'y');
	copy_map->num_collectible = count_character(map, 'C');
	copy_map->verify_collectible = count_character(map, 'C');
	copy_map->verify_exit = 0;
	return (copy_map);
}
