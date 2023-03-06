/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/14 18:43:08 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	Initialize pixels by running the projections and align functions.
*/
void	init_pixels(t_map ***map, t_draw *draw)
{
	t_map	**tmp;

	tmp = *map;
	update_pixels(&tmp, draw, &projection);
	draw->offset = ft_distance(map, draw);
	update_pixels(&tmp, draw, &align_to_display);
}

/*
**	Loop and update pixels based on function ran.
*/
void	update_pixels(t_map ***map, t_draw *draw, \
void (*f)(t_map ***, int, int, t_draw *))
{
	t_map	**tmp;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	while (y < draw->height)
	{
		x = 0;
		while (x < draw->width)
		{
			f(&tmp, x, y, draw);
			x++;
		}
		y++;
	}
}

/*	Modifies pixel values based on projection and scale	*/
void	projection(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	tmp = *map;
	tmp[y][x].pix_x = ((x - y) * cos(draw->angle)) * draw->scale;
	tmp[y][x].pix_y = ((x + y) * sin(draw->angle) - tmp[y][x].z) * draw->scale;
}

/*	Align display to to left	*/
void	align_to_display(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	tmp = *map;
	tmp[y][x].pix_x += ZONE_X + draw->offset.x;
	tmp[y][x].pix_y += ZONE_Y + draw->offset.y;
}
