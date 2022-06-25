/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:45:49 by lharkala          #+#    #+#             */
/*   Updated: 2022/06/19 22:33:04 by lharkala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	Gets the rounded up square root.		*/

int	round_up_sqrt(int n)
{
	int	map_size;

	map_size = 2;
	while (map_size * map_size < n)
		map_size++;
	return (map_size);
}

/*	Frees the memory in the list.			*/

void	free_tlist(t_etris **tlist)
{
	t_etris	*temp;

	while (*tlist)
	{
		temp = (*tlist);
		(*tlist) = (*tlist)->next;
		free(temp);
	}
	free (tlist);
	temp = NULL;
}

/*	Frees the memory within the map as well as the array.		*/

void	free_map(t_map *map, int map_size)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}
