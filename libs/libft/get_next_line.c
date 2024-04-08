/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:17:02 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/04/08 14:36:44 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rest_line(char *line)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!(line[i]))
	{
		free (line);
		return (NULL);
	}
	while (line[j] != '\0')
		j++;
	rest = (char *)malloc ((j - i) * sizeof(char));
	if (!rest)
		return (0);
	j = 0;
	while (line[i++] != '\0')
	{
		rest[j++] = line[i];
	}
	free (line);
	return (rest);
}

static char	*cut_line(char *line)
{
	int		i;
	int		j;
	char	*print_line;

	i = 0;
	j = 0;
	if (!*line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	print_line = (char *)malloc ((i + 2) * sizeof(char));
	if (!print_line)
		return (0);
	while (line[j] && line[j] != '\n')
	{
		print_line[j] = line[j];
		j++;
	}
	if (line[j] == '\n')
		print_line[j++] = '\n';
	print_line[j] = '\0';
	return (print_line);
}

static char	*read_line(int fd, char *line)
{
	int		line_bytes;
	char	*buf;

	line_bytes = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (line_bytes > 0 && !gnl_ft_strchr(line, '\n'))
	{
		line_bytes = read(fd, buf, BUFFER_SIZE);
		if (line_bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[line_bytes] = '\0';
		line = gnl_ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = read_line(fd, file);
	if (!file)
		return (NULL);
	line = cut_line(file);
	file = rest_line(file);
	return (line);
}
