/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:35:04 by oseitama          #+#    #+#             */
/*   Updated: 2022/10/14 18:40:49 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

/*
**	Initialize MLX
*/
void	init_mlx_and_img(t_fdf *fdf)
{
	init(fdf);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		exit_fdf(fdf);
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!fdf->win)
		exit_fdf(fdf);
	fdf->img->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img->image)
		exit_fdf(fdf);
	fdf->img->addr = mlx_get_data_addr(fdf->img->image, &fdf->img->\
	bits_per_pixel, &fdf->img->line_length, &fdf->img->endian);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->image, 0, 0);
}

void	init(t_fdf *fdf)
{
	fdf->mlx = 0;
	fdf->win = 0;
	fdf->img = (t_img *) malloc(sizeof(t_img));
	fdf->img->image = 0;
	fdf->img->addr = NULL;
	fdf->img->bits_per_pixel = 0;
	fdf->img->line_length = 0;
	fdf->img->endian = 10;
	fdf->draw = (t_draw *) malloc(sizeof(t_draw));
	fdf->draw->height = 0;
	fdf->draw->width = 0;
	fdf->draw->map_diag = 0;
	fdf->draw->scale_width = 0;
	fdf->draw->scale_height = 0;
	fdf->draw->scale = 0;
	fdf->draw->map_width = 0;
	fdf->draw->map_height = 0;
	fdf->draw->angle = 0;
	fdf->draw->projection = 1;
}

void	reset_to_default(t_fdf *fdf)
{
	fdf->draw->angle = ISOMETRIC;
	fdf->draw->scale = ft_min(fdf->draw->scale_width, fdf->draw->scale_height);
}

void	update_settings(t_fdf *fdf)
{
	fdf->draw->angle = ISOMETRIC;
	fdf->draw->map_diag = ft_abs((sqrt(\
	pow(fdf->draw->height, 2) + pow(fdf->draw->width, 2))));
	fdf->draw->scale_width = ((ZONE_WIDTH / fdf->draw->map_diag));
	fdf->draw->scale_height = ((ZONE_HEIGHT / fdf->draw->map_diag));
	fdf->draw->scale = ft_min(fdf->draw->scale_width, fdf->draw->scale_height);
	fdf->draw->map_width = (fdf->draw->width * fdf->draw->scale);
	fdf->draw->map_height = (fdf->draw->height * fdf->draw->scale);
}
