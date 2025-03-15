/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:29:20 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/24 17:35:40 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *argv)
{
	char	*ext;
	int		i;
	int		j;

	i = 0;
	j = 3;
	ext = ".ber";
	while (argv[i] != '\0')
		i++;
	i--;
	while (j >= 0)
	{
		if (argv[i] != ext[j])
			return (EXTENSION_ERROR);
		i--;
		j--;
	}
	if (i < 0)
		return (EXTENSION_ERROR);
	return (NONE_ERROR);
}

int	count_character(char **map, char c)
{
	int	i;
	int	j;
	int	count_character;

	i = 0;
	count_character = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count_character += 1;
			j++;
		}
		i++;
	}
	return (count_character);
}

int	number_character(char **map)
{
	if ((count_character(map, 'P') != 1) || (count_character(map, 'E') != 1))
		return (CHARACTER_ERROR);
	if (count_character(map, 'C') == 0)
		return (CHARACTER_ERROR);
	return (NONE_ERROR);
}

int	map_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '\n')
				return (CHARACTER_ERROR);
			j++;
		}
		i++;
	}
	return (NONE_ERROR);
}
