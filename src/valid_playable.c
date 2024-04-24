/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_playable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:05:50 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/24 17:40:53 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_map(t_map *copy_map, int x, int y)
{
	if (copy_map->map[y][x] == 'C')
		copy_map->verify_collectible--;
	if (copy_map->map[y][x] == 'E')
	{
		copy_map->verify_exit = 1;
		copy_map->map[y][x] = '1';
	}
	if (x < 1 || x > copy_map->width || y < 1 || y > copy_map->height
		|| copy_map->map[y][x] == '1')
		return ;
	copy_map->map[y][x] = '1';
	fill_map(copy_map, x - 1, y);
	fill_map(copy_map, x + 1, y);
	fill_map(copy_map, x, y - 1);
	fill_map(copy_map, x, y + 1);
}

int	playable_map(char **map)
{
	t_map	*copy_map;

	copy_map = struct_map(map);
	fill_map(copy_map, copy_map->x_player, copy_map->y_player);
	if (copy_map->verify_collectible != 0 || copy_map->verify_exit == 0)
		return (PLAYABLE_ERROR);
	free_matrix(copy_map->map);
	free(copy_map);
	return (NONE_ERROR);
}

int	error_messages(int error)
{
	ft_putstr_fd("Error\n", 2);
	if (error == -1)
		ft_putstr_fd("Wrong numbers of arguments, expected 2.\n", 2);
	else if (error == -2)
		ft_putstr_fd("Invalid extension path, expected .ber file.\n", 2);
	else if (error == -3)
		ft_putstr_fd("Error opening the map file.\n", 2);
	else if (error == -4)
		ft_putstr_fd("Invalid characters.\n", 2);
	else if (error == -5)
		ft_putstr_fd("The map is not retangular.\n", 2);
	else if (error == -6)
		ft_putstr_fd("The map is not surrounded by walls.\n", 2);
	else if (error == -7)
		ft_putstr_fd("The map has no valid path for winning.\n", 2);
	return (error);
}

int	check_errors(char **map)
{
	if (number_character(map) == CHARACTER_ERROR
		|| map_characters(map) == CHARACTER_ERROR)
		return (error_messages(CHARACTER_ERROR));
	else if (rectangular_map(map) == RECTANGULAR_ERROR)
		return (error_messages(RECTANGULAR_ERROR));
	else if (check_wall(map) == WALL_ERROR)
		return (error_messages(WALL_ERROR));
	else if (playable_map(map) == PLAYABLE_ERROR)
		return (error_messages(PLAYABLE_ERROR));
	return (NONE_ERROR);
}
