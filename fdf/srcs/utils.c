/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/12 23:36:06 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	ft_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_point	ft_distance(t_map ***map, t_draw *draw)
{
	t_point	leftest_pix;
	t_point	highest_pix;
	t_point	offset;

	leftest_pix = ft_pix_leftest(map, draw);
	highest_pix = ft_pix_highest(map, draw);
	offset.x = map[0][0]->pix_x - leftest_pix.x;
	offset.y = map[0][0]->pix_y - highest_pix.y;
	return (offset);
}

t_point	ft_pix_leftest(t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	t_point	point;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	x = 0;
	point.x = tmp[y][x].pix_x;
	point.y = tmp[y][x].pix_y;
	while (y < draw->height)
	{
		x = 0;
		while (x < draw->width)
		{
			if (point.x > tmp[y][x].pix_x)
			{
				point.x = tmp[y][x].pix_x;
				point.y = tmp[y][x].pix_y;
			}
			x++;
		}
		y++;
	}
	return (point);
}

t_point	ft_pix_highest(t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	t_point	point;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	x = 0;
	point.x = tmp[y][x].pix_x;
	point.y = tmp[y][x].pix_y;
	while (y < draw->height)
	{
		x = 0;
		while (x < draw->width)
		{
			if (point.y > tmp[y][x].pix_y)
			{
				point.x = tmp[y][x].pix_x;
				point.y = tmp[y][x].pix_y;
			}
			x++;
		}
		y++;
	}
	return (point);
}
