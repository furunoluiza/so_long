/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:30:10 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/24 17:45:48 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	wall_horizontal(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != '\n')
			return (1);
		j++;
	}
	while (map[i])
		i++;
	i--;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != '\n')
			return (1);
		j++;
	}
	return (0);
}

static int	wall_vertical(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
		j++;
	j -= 2;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_wall(char **map)
{
	if (wall_horizontal(map) || wall_vertical(map))
		return (WALL_ERROR);
	return (NONE_ERROR);
}

static int	size_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	rectangular_map(char **map)
{
	int	i;
	int	width;

	i = 0;
	width = size_line(map[0]);
	while (map[i])
	{
		if (width != size_line(map[i]))
			return (RECTANGULAR_ERROR);
		i++;
	}
	if (i == width)
		return (RECTANGULAR_ERROR);
	return (NONE_ERROR);
}
