/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:33:16 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/27 00:13:29 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	Prints the map.		*/

void	print_map(t_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

/*	Creates a new map and allocates memory to both the map and the	*/
/*	array within it.  fills each initial slot with '.'				*/

t_map	*new_map(int map_size)
{
	t_map	*map;
	int		i;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->array = (char **)ft_memalloc(sizeof(char *) * map_size);
	i = 0;
	while (i < map_size)
	{
		map->array[i] = ft_strnew(map_size);
		ft_memset(map->array[i], '.', map_size);
		i++;
	}
	return (map);
}
