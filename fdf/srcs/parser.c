/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/14 18:42:25 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

t_map	**parse(char *file_name, int *height, int *width)
{
	t_map	**map;

	get_mapdim(file_name, height, width);
	map = map_create(file_name, *height, *width);
	return (map);
}

/*
**	Get map dimensions
*/
void	get_mapdim(char *file_name, int *height, int *width)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_putstr_fd("Impossible to open the specific file.\n", 2);
		exit(0);
	}
	get_next_line(fd, &line);
	*width = word_counter(line, ' ');
	(*height)++;
	free(line);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (word_counter(line, ' ') != 0)
			(*height)++;
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(fd);
}

/*
**	save z values from file into
*/
void	put_value(t_map *row, char *line)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_strsplit(line, ' ');
	while (split[j])
	{
		row[j].z = ft_atoi_base(split[j], 10);
		row[j].pix_x = 0;
		row[j].pix_y = 0;
		if (!ft_strchr(split[j], ','))
			row[j].color = COLOR_INIT;
		else
			row[j].color = ft_atoi_base(ft_strchr(split[j], ',') + 3, 16);
		j++;
	}
	free_split(split);
}
