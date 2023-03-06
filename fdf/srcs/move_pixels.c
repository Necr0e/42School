/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/14 18:41:44 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_up(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	if (draw)
		;
	tmp = *map;
	tmp[y][x].pix_y += MOVEMENT_STEP;
}

void	move_down(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	if (draw)
		;
	tmp = *map;
	tmp[y][x].pix_y -= MOVEMENT_STEP;
}

void	move_left(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	if (draw)
		;
	tmp = *map;
	tmp[y][x].pix_x += MOVEMENT_STEP;
}

void	move_right(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	if (draw)
		;
	tmp = *map;
	tmp[y][x].pix_x -= MOVEMENT_STEP;
}

void	zoom(t_fdf *fdf, float value)
{
	if ((value == 2 && fdf->draw->scale * 2 < 300) || \
		(value == 0.5 && fdf->draw->scale / 2 != 0))
	{
		fdf->draw->scale *= value;
		init_pixels(&fdf->map, fdf->draw);
		put_img(fdf);
	}
}
