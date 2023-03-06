/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/14 18:39:41 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	exit_fdf(t_fdf *fdf)
{
	if (fdf->map)
		map_free(fdf->map, fdf->draw->height);
	if (fdf->draw)
		free(fdf->draw);
	if (fdf->img->image)
		mlx_destroy_image(fdf->mlx, fdf->img->image);
	if (fdf->img)
		free(fdf->img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
	return (0);
}

void	map_free(t_map **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}
