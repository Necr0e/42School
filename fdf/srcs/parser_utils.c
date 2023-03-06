/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/12 23:36:41 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted[i]);
	free(splitted);
}

int	word_counter(const char *line, const char chr)
{
	int	i;
	int	word_counter;

	i = 0;
	word_counter = 0;
	while (line[i])
	{
		if (line[i] == chr)
			i++;
		else
		{
			word_counter++;
			while (line[i] != '\0' && line[i] != chr)
				i++;
		}
	}
	return (word_counter);
}

t_map	**map_alloc(int height, int width)
{
	t_map	**map;
	int		i;

	i = 0;
	map = (t_map **)malloc(sizeof(t_map *) * height);
	while (i < height)
		map[i++] = (t_map *)malloc(sizeof(t_map) * width);
	return (map);
}

t_map	**map_create(char *file_name, int height, int width)
{
	int		i;
	t_map	**map;
	char	*line;
	int		fd;

	i = 0;
	line = NULL;
	map = map_alloc(height, width);
	fd = open(file_name, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		if (word_counter(line, ' ') != 0)
		{
			put_value(map[i], line);
			i++;
		}
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(fd);
	return (map);
}
