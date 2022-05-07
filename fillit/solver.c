/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:38:03 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/27 12:55:28 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	Checks for piece overlap.		*/

static int	overlap(t_map *map, t_etris *piece)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	x = piece->coords[i].x + piece->x_offset;
	y = piece->coords[i].y + piece->y_offset;
	while (i <= 3 && map->array[y][x] == '.')
	{
		i++;
		x = piece->coords[i].x + piece->x_offset;
		y = piece->coords[i].y + piece->y_offset;
	}
	return (i != 4);
}

/*	Checks that the piece to be placed is within the map.	*/

static int	in_bounds(t_etris *piece, int map_size, char axis)
{
	int	i;

	i = 0;
	if (axis == 'y')
	{
		while (i < 4)
		{
			if (piece->coords[i].y + piece->y_offset >= map_size)
				return (0);
			i++;
		}
	}
	else
	{
		while (i < 4)
		{
			if (piece->coords[i].x + piece->x_offset >= map_size)
				return (0);
			i++;
		}
	}
	return (1);
}

/*	Place defined letter on the map.		*/

static void	place(t_etris *piece, t_map *map, char value)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 3)
	{
		x = piece->coords[i].x + piece->x_offset;
		y = piece->coords[i].y + piece->y_offset;
		map->array[y][x] = value;
		i++;
	}
}

/*	Backtracking implementation of the solver.							*/
/*	Loops through the map, checkikng if it can place					*/
/*	a tetrimino, if so, it checks if theres another tetrimino to place	*/
/*	Returns 0 on solving being done, otherwise 1.						*/

static int	solve_map(t_map	*map, t_etris *piece, int map_size)
{
	if (!piece)
		return (1);
	piece->x_offset = 0;
	piece->y_offset = 0;
	while (in_bounds(piece, map_size, 'y'))
	{
		while (in_bounds(piece, map_size, 'x'))
		{
			if (!overlap(map, piece))
			{
				place(piece, map, piece->value);
				if (solve_map(map, piece->next, map_size))
					return (1);
				else
				{
					place(piece, map, '.');
				}
			}
			piece->x_offset++;
		}
		piece->x_offset = 0;
		piece->y_offset++;
	}
	return (0);
}

/*	Initial solver, tries to solve map witht he smallest map size	*/

void	solve(t_etris *piecelist, int piececount)
{
	t_map	*map;
	int		map_size;

	map_size = round_up_sqrt(piececount * 4);
	map = new_map(map_size);
	while (!solve_map(map, piecelist, map_size))
	{
		free_map(map, map_size);
		map_size++;
		map = new_map(map_size);
	}
	print_map(map, map_size);
	free_map(map, map_size);
}
