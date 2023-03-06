/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/14 18:37:34 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	Flip to reverse color.
*/
void	color_update(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	if (draw)
		;
	tmp = *map;
	tmp[y][x].color = get_opposite_color(tmp[y][x].color);
}

/*	Change projection from isometric to cavalier when key is pressed.	*/
void	change_projection(t_fdf *fdf)
{
	fdf->draw->projection++;
	if (fdf->draw->projection == 100)
		fdf->draw->projection = 0;
	if (fdf->draw->projection % 2)
		fdf->draw->angle = ISOMETRIC;
	else
		fdf->draw->angle = CAVALIER;
	init_pixels(&fdf->map, fdf->draw);
	put_img(fdf);
}
